/*
** EPITECH PROJECT, 2024
** read_param
** File description:
** read_param
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


void reset_dir(param_t *list)
{
    for (int i = 0; list[i].type != 0; i++) {
        if (list[i].size == 4)
            list[i].size = 2;
    }
}

param_t *read_param(int len, char *bin)
{
    param_t *list = malloc(sizeof(param_t) * (len + 1));
    int ind = 0;

    for (int i = 0; i < len; i++) {
        if (bin[ind] == '1' && bin[ind + 1] == '0') {
            list[i].type = T_DIR;
            list[i].size = 4;
        }
        if (bin[ind] == '1' && bin[ind + 1] == '1') {
            list[i].type = T_IND;
            list[i].size = 2;
        }
        if (bin[ind] == '0' && bin[ind + 1] == '1') {
            list[i].type = T_REG;
            list[i].size = 1;
        }
        ind += 2;
    }
    list[len].type = 0;
    return list;
}

int pick_direct(int pc, corewar_t *game)
{
    union intconverter converter;
    int address = pc + 1;

    converter.bytes[0] = game->board[(address + 3) % MEM_SIZE];
    converter.bytes[1] = game->board[(address + 2) % MEM_SIZE];
    converter.bytes[2] = game->board[(address + 1) % MEM_SIZE];
    converter.bytes[3] = game->board[address % MEM_SIZE];
    return converter.value;
}

int pick_indirect(int pc, corewar_t *game)
{
    union intconverter converter;
    int address = pc + 1;

    converter.bytes[0] = game->board[(address + 1) % MEM_SIZE];
    converter.bytes[1] = game->board[address % MEM_SIZE];
    converter.bytes[2] = 0;
    converter.bytes[3] = 0;
    return converter.value;
}

static int pick_reg(int pc, corewar_t *game)
{
    int address = pc + 1;

    return game->board[address % MEM_SIZE];
}

void fill_value(champ_t *champ, corewar_t *game, param_t *list, int len)
{
    int pc = champ->pc + 1;

    for (int i = 0; i < len; i++) {
        if (list[i].type == T_DIR)
            list[i].value = pick_direct(pc, game);
        if (list[i].type == T_IND)
            list[i].value = pick_indirect(pc, game);
        if (list[i].type == T_REG) {
            list[i].value = pick_reg(pc, game);
        }
        pc += list[i].size;
    }
    return;
}
