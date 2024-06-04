/*
** EPITECH PROJECT, 2024
** nbr_live
** File description:
** manage live
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

void manage_cycle_to_die(corewar_t *game)
{
    if (game->nbr_live >= NBR_LIVE) {
        game->cycle_die -= game->cycle_delta;
        game->nbr_live = 0;
    }
}
