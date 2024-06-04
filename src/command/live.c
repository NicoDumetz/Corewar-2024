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
    int address = champ->pc + 1;

    converter.bytes[0] = game->board[(address + 3) % MEM_SIZE];
    converter.bytes[1] = game->board[(address + 2) % MEM_SIZE];
    converter.bytes[2] = game->board[(address + 1) % MEM_SIZE];
    converter.bytes[3] = game->board[address % MEM_SIZE];
    for (; temp; temp = temp->next) {
        if (temp->index == converter.value) {
            my_printf("The player %d (%s) is alive.\n", temp->index,
            temp->name);
            temp->cycle_die = game->cycle_die;
            game->nbr_live++;
            add_pc(champ, 5);
            return;
        }
    }
    add_pc(champ, 5);
    return;
}
