/*
** EPITECH PROJECT, 2024
** init memory
** File description:
** init memory
*/

#include "corewar.h"
#include "op.h"
#include "my.h"
#include "stddef.h"
#include <sys/stat.h>


int len_hero(corewar_t *game)
{
    champ_t *champ = game->list;
    int nbr = 0;

    for (; champ; champ = champ->next)
        nbr++;
    return nbr;
}

void write_code_champ(corewar_t *game, int pos, champ_t *champ)
{
    for (int k = 0; k < champ->prog_size; k++) {
        if (pos == MEM_SIZE)
            pos = 0;
        game->board[pos] = champ->code[k];
        pos++;
    }
    return;
}

int init_memory(corewar_t *game)
{
    game->cycle_delta = CYCLE_DELTA;
    game->cycle_die = CYCLE_TO_DIE;
    game->len_hero = len_hero(game);
    game->nbr_live = 0;
    game->last_name = NULL;
    game->last_index = 0;
    for (int i = 0; i < MEM_SIZE; i++)
        game->board[i] = 0;
    if (set_pc_champ(game))
        return 1;
    for (champ_t *current = game->list; current; current = current->next)
        write_code_champ(game, current->pc, current);
    return 0;
}
