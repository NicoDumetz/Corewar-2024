/*
** EPITECH PROJECT, 2024
** lfork
** File description:
** lfork
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


void lfork_cor(champ_t *champ, corewar_t *game)
{
    champ_t *new = malloc(sizeof(champ_t));
    int pc = champ->pc + 1;
    union intconverter converter;
    short value = 0;

    converter.bytes[0] = game->board[(pc + 1) % MEM_SIZE];
    converter.bytes[1] = game->board[pc % MEM_SIZE];
    converter.bytes[2] = 0;
    converter.bytes[3] = 0;
    value = converter.value;
    copy_of_champ(champ, new);
    new->pc = champ->pc + value;
    if (new->pc < 0) {
        new->pc += MEM_SIZE;
    } else if (new->pc >= MEM_SIZE)
        new->pc %= MEM_SIZE;
    insert_champ(new, game);
    add_pc(champ, 3);
    return;
}
