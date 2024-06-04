/*
** EPITECH PROJECT, 2024
** fork
** File description:
** fork
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


void copy_of_champ(champ_t *champ, champ_t *new)
{
    new->name = champ->name;
    new->prog_size = champ->prog_size;
    new->filename = champ->filename;
    new->comment = champ->comment;
    new->all = my_strdup(champ->all);
    new->code = my_strdup(champ->code);
    for (int i = 0; i < REG_NUMBER; i++)
        new->reg[i] = champ->reg[i];
    new->carry = champ->carry;
    new->alive = champ->alive;
    new->cycle_die = champ->cycle_die;
    new->index = champ->index;
    new->wait = -1;
}

void fork_cor(champ_t *champ, corewar_t *game)
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
    new->pc = champ->pc + (value % IDX_MOD);
    if (new->pc < 0) {
        new->pc += MEM_SIZE;
    } else if (new->pc >= MEM_SIZE)
        new->pc %= MEM_SIZE;
    new->pc = new->pc;
    insert_champ(new, game);
    add_pc(champ, 3);
    return;
}
