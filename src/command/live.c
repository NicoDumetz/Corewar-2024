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

void live(champ_t *champ, corewar_t *game)
{
    union intconverter converter;
    champ_t *temp = game->list;

    converter.bytes[0] = game->board[champ->pc + 4];
    converter.bytes[1] = game->board[champ->pc + 3];
    converter.bytes[2] = game->board[champ->pc + 2];
    converter.bytes[3] = game->board[champ->pc + 1];
    for (; temp; temp = temp->next) {
        if (temp->index == converter.value) {
            my_printf("Le joueur %d (%s) est en vie.\n", temp->index,
            temp->name);
            temp->cycle_die = game->cycle_die;
        }
    }
    add_pc(champ, 5);
    return;
}
