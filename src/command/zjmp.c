/*
** EPITECH PROJECT, 2024
** zjmp
** File description:
** zjmp
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


void zjmp(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    union intconverter converter;
    short value = 0;

    converter.bytes[0] = game->board[(pc + 1) % MEM_SIZE];
    converter.bytes[1] = game->board[pc % MEM_SIZE];
    converter.bytes[2] = 0;
    converter.bytes[3] = 0;
    value = converter.value;
    if (champ->carry == 1) {
        add_pc(champ, value);
        return;
    }
    add_pc(champ, 3);
    return;
}
