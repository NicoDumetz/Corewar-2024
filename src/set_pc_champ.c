/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** set_champ.c
*/

#include "corewar.h"
#include "errors.h"

static bool champ_overlap(champ_t *champ_pos[5], int i)
{
    bool overlap;
    int start_i = champ_pos[i]->pc;
    int end_i = (start_i + champ_pos[i]->prog_size) % MEM_SIZE;
    int start_j;
    int end_j;

    for (int j = i + 1; champ_pos[j]; j++) {
        start_j = champ_pos[j]->pc;
        end_j = (start_j + champ_pos[j]->prog_size) % MEM_SIZE;
        overlap =
        (start_i < end_i && (start_j >= start_i && start_j < end_i)) ||
        (start_i > end_i && (start_j >= start_i || start_j < end_i)) ||
        (start_j < end_j && (start_i >= start_j && start_i < end_j)) ||
        (start_j > end_j && (start_i >= start_j || start_i < end_j));
        if (overlap)
            return true;
    }
    return false;
}

static unsigned char count_set_champ(corewar_t *game)
{
    unsigned char count = 0;

    for (champ_t *current = game->list; current; current = current->next) {
        if (current->pc != -1)
            count++;
    }
    return count;
}

static void add_to_list(champ_t *champ, champ_t *champ_pos[5])
{
    unsigned char pos;

    for (pos = 0; champ_pos[pos] && champ_pos[pos]->pc <= champ->pc; pos++);
    for (signed char end = 3; end >= pos; end--)
        champ_pos[end + 1] = champ_pos[end];
    champ_pos[pos] = champ;
}

static void init_list(corewar_t *game, champ_t *champ_pos[5])
{
    for (champ_t *current = game->list; current; current = current->next) {
        if (current->pc == -1)
            continue;
        add_to_list(current, champ_pos);
    }
}

static void set_champ_zero_one(champ_t *champ_pos[5], corewar_t *game)
{
    int pos = (champ_pos[0]) ? champ_pos[0]->pc : 0;
    int div = MEM_SIZE / game->len_hero;

    pos += (champ_pos[0]) ? div : 0;
    for (champ_t *current = game->list; current; current = current->next) {
        if (current->pc != -1)
            continue;
        pos %= MEM_SIZE;
        current->pc = pos;
        add_to_list(current, champ_pos);
        pos += div;
    }
}

static void set_one_each(int free1[2], int free2[2], champ_t *champ_pos[5],
    corewar_t *game)
{
    champ_t *current = game->list;

    for (; current && current->pc != -1; current = current->next);
    if (!current)
        return;
    current->pc = free1[0] + (free1[1] / 2) - current->prog_size;
    add_to_list(current, champ_pos);
    for (current = game->list; current && current->pc != -1;
    current = current->next);
    if (!current)
        return;
    current->pc = free2[0] + (free2[1] / 2) - current->prog_size;
    current->pc %= MEM_SIZE;
    add_to_list(current, champ_pos);
}

static void set_champ_two_left(int free1[2], int free2[2],
    champ_t *champ_pos[5], corewar_t *game)
{
    int div;
    champ_t *current = game->list;

    if (!(free1[1] / 3 > free2[1] / 2 || free2[1] / 3 > free1[1] / 2))
        return set_one_each(free1, free2, champ_pos, game);
    free1[0] = (free1[1] > free2[1]) ? free1[0] : free2[0];
    free1[1] = (free1[1] > free2[1]) ? free1[1] : free2[1];
    div = free1[1] / 3;
    for (; current; current = current->next) {
        if (current->pc != -1)
            continue;
        current->pc = free1[0] + div;
        current->pc %= MEM_SIZE;
        add_to_list(current, champ_pos);
        div += div;
    }
}

static void set_champ_two(champ_t *champ_pos[5], corewar_t *game)
{
    int free1[2] = {champ_pos[0]->pc + champ_pos[0]->prog_size,
    champ_pos[1]->pc - (champ_pos[0]->pc + champ_pos[0]->prog_size)};
    int free2[2] = {champ_pos[1]->pc + champ_pos[1]->prog_size, MEM_SIZE
    - (champ_pos[1]->pc + champ_pos[1]->prog_size) + champ_pos[0]->pc};
    champ_t *current = game->list;

    if (game->len_hero == 2)
        return;
    if (game->len_hero == 4)
        return set_champ_two_left(free1, free2, champ_pos, game);
    free1[0] = (free1[1] > free2[1]) ? free1[0] : free2[0];
    free1[1] = (free1[1] > free2[1]) ? free1[1] : free2[1];
    for (; current && current->pc != -1; current = current->next);
    if (!current)
        return;
    current->pc = (free1[0] + (free1[1] / 2)) - current->prog_size / 2;
    current->pc %= MEM_SIZE;
    add_to_list(current, champ_pos);
}

static void set_champ_three(champ_t *champ_pos[5], corewar_t *game)
{
    champ_t *current = game->list;
    int free[2] = {champ_pos[0]->pc + champ_pos[0]->prog_size,
    champ_pos[1]->pc - (champ_pos[0]->pc + champ_pos[0]->prog_size)};
    int tmp = champ_pos[2]->pc -
    (champ_pos[1]->pc + champ_pos[1]->prog_size);

    if (tmp > free[1]) {
        free[0] = champ_pos[1]->pc + champ_pos[1]->prog_size;
        free[1] = tmp;
    }
    tmp = MEM_SIZE - (champ_pos[2]->pc + champ_pos[2]->prog_size) +
    champ_pos[1]->prog_size;
    if (tmp > free[1]) {
        free[0] = champ_pos[2]->pc + champ_pos[2]->prog_size;
        free[1] = tmp;
    }
    for (; current && current->pc != -1; current = current->next);
    current->pc = (free[0] + (free[1] / 2)) - current->prog_size / 2;
    current->pc %= MEM_SIZE;
    add_to_list(current, champ_pos);
}

int set_pc_champ(corewar_t *game)
{
    unsigned char nb_set = count_set_champ(game);
    champ_t *champ_pos[5] = {0, 0, 0, 0, 0};

    init_list(game, champ_pos);
    if (nb_set == 0 || nb_set == 1)
        set_champ_zero_one(champ_pos, game);
    if (nb_set == 2)
        set_champ_two(champ_pos, game);
    if (nb_set == 3 && game->len_hero != 3)
        set_champ_three(champ_pos, game);
    for (unsigned char i = 0; champ_pos[i]; i++) {
        if (champ_overlap(champ_pos, i))
            return write(2, OVERLAP, my_strlen(OVERLAP));
    }
    return 0;
}
