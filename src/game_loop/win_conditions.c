/*
** EPITECH PROJECT, 2024
** win_conditions
** File description:
** wind
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

static int check_same_index(corewar_t *game, int nbr)
{
    champ_t *champ = game->list;
    champ_t *tmp;

    for (; champ->alive != 1; champ = champ->next);
    tmp = champ;
    for (; tmp; tmp = tmp->next) {
        if (tmp->alive == 1 && tmp->index != champ->index)
            return nbr;
    }
    return 1;
}

int how_many_are_alive(corewar_t *game)
{
    champ_t *champ = game->list;
    int nbr = 0;

    for (; champ; champ = champ->next) {
        if (champ->cycle_die <= 0)
            champ->alive = 0;
    }
    champ = game->list;
    for (; champ; champ = champ->next) {
        if (champ->alive == 1)
            nbr++;
    }
    if (nbr > 1)
        nbr = check_same_index(game, nbr);
    return nbr;
}

void display_winner(corewar_t *game)
{
    champ_t *champ = game->list;

    if (game->last_index == 0 && game->last_name == NULL) {
        my_printf("There are no winner.\n");
        return;
    }
    if (how_many_are_alive(game) != 1) {
        my_printf("The player %d (%s) has won.\n",
            game->last_index, game->last_name);
        return;
    }
    for (; champ; champ = champ->next) {
        if (champ->alive == 1) {
            my_printf("The player %d (%s) has won.\n",
            champ->index, champ->name);
            break;
        }
    }
    return;
}
