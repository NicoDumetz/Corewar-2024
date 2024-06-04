/*
** EPITECH PROJECT, 2024
** live
** File description:
** live
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

static void set_index(champ_t *temp, int value, corewar_t *game)
{
    for (temp = game->list; temp; temp = temp->next) {
        if (temp->index == value) {
            temp->cycle_die = game->cycle_die;
        }
    }
}

static void set_live_reset(champ_t *temp, corewar_t *game, int *print)
{
    *print = 1;
    my_printf("The player %d (%s) is alive.\n", temp->index,
    temp->name);
    temp->cycle_die = game->cycle_die;
    game->nbr_live++;
    game->last_index = temp->index;
    game->last_name = temp->name;
}

static void skip_live(champ_t *temp, int value,
    corewar_t *game, champ_t *champ)
{
    set_index(temp, value, game);
    add_pc(champ, 5);
    return;
}

void live(champ_t *champ, corewar_t *game)
{
    champ_t *temp = game->list;
    int address = champ->pc + 1;
    int value = read_int_from_memory(game, address);
    int print = 0;

    if (champ->cycle_die >= game->cycle_die)
        return skip_live(temp, value, game, champ);
    if (champ->cycle_die == game->cycle_die - 1) {
        champ->cycle_die++;
        game->nbr_live++;
        return skip_live(temp, value, game, champ);
    }
    for (; temp; temp = temp->next) {
        if (temp->index == value && print == 1 && temp->alive == 1)
            temp->cycle_die = game->cycle_die;
        if (temp->index == value && print == 0 && temp->alive == 1)
            set_live_reset(temp, game, &print);
    }
    return skip_live(temp, value, game, champ);
}
