/*
** EPITECH PROJECT, 2024
** live
** File description:
** live
*/

#include "../../include/corewar.h"
#include "../../include/op.h"
#include "../../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

void live(champ_t *champ, corewar_t *game)
{
    champ_t *temp = game->list;
    int address = champ->pc + 1;
    int value = read_int_from_memory(game, address);

    for (; temp; temp = temp->next) {
        if (temp->index == value) {
            my_printf("The player %d (%s) is alive.\n", temp->index,
            temp->name);
            temp->cycle_die = game->cycle_die;
            game->nbr_live++;
            game->last_index = temp->index;
            game->last_name = temp->name;
            break;
        }
    }
    for (temp = game->list; temp; temp = temp->next) {
        if (temp->index == value) {
            temp->cycle_die = game->cycle_die;
        }
    }
    add_pc(champ, 5);
    return;
}
