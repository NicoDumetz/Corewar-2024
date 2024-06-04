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

int how_many_are_alive(corewar_t *game)
{
    champ_t *champ = game->list;
    int nbr = 0;

    for (; champ; champ = champ->next) {
        if (champ->alive == 1)
            nbr++;
    }
    return nbr;
}

void display_winner(corewar_t *game)
{
    champ_t *champ = game->list;

    if (how_many_are_alive(game) != 1)
        return;
    for (; champ; champ = champ->next) {
        if (champ->alive == 1) {
            my_printf("Le joueur %d (%s) a gagné.\n",
            champ->index, champ->name);
            break;
        }
    }
    return;
}
