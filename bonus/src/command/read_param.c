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

static int pick_direct(int pc, corewar_t *game)
{
    union intconverter converter;
    int address = pc + 1;

    converter.bytes[0] = game->board[(address + 3) % MEM_SIZE].c;
    converter.bytes[1] = game->board[(address + 2) % MEM_SIZE].c;
    converter.bytes[2] = game->board[(address + 1) % MEM_SIZE].c;
    converter.bytes[3] = game->board[address % MEM_SIZE].c;
    return converter.value;
}

static int pick_indirect(int pc, corewar_t *game)
{
    union intconverter converter;
    int address = pc + 1;

    converter.bytes[0] = game->board[(address + 1) % MEM_SIZE].c;
    converter.bytes[1] = game->board[address % MEM_SIZE].c;
    converter.bytes[2] = 0;
    converter.bytes[3] = 0;
    return converter.value;
}

static int pick_reg(int pc, corewar_t *game)
{
    int address = pc + 1;

    return game->board[address % MEM_SIZE].c;
}

void fill_value_except(champ_t *champ, corewar_t *game, param_t *list, int len)
{
    int pc = champ->pc + 1;

    for (int i = 0; i < len; i++) {
        if (list[i].type == T_DIR)
            list[i].value = pick_indirect(pc, game);
        if (list[i].type == T_IND)
            list[i].value = pick_indirect(pc, game);
        if (list[i].type == T_REG) {
            list[i].value = pick_reg(pc, game);
        }
        pc += list[i].size;
    }
    return;
}

static param_t *init_list(int len)
{
    param_t *list = malloc(sizeof(param_t) * (len + 1));

    for (int i = 0; i < len; i++) {
        list[i].size = 0;
        list[i].type = 0;
        list[i].value = 0;
    }
    return list;
}

param_t *read_param_except(int len, char *bin)
{
    param_t *list = init_list(len);
    int ind = 0;
    int num = 0;

    for (int i = 0; i < len; i++) {
        num += fill_types_except(list, i, bin, ind);
        ind += 2;
    }
    list[len].type = 0;
    if (num != len) {
        free(list);
        return NULL;
    }
    return list;
}

static int fill_types(param_t *list, int i, char *bin, int ind)
{
    if (bin[ind] == '1' && bin[ind + 1] == '0') {
        list[i].type = T_DIR;
        list[i].size = 4;
        return 1;
    }
    if (bin[ind] == '1' && bin[ind + 1] == '1') {
        list[i].type = T_IND;
        list[i].size = 2;
        return 1;
    }
    if (bin[ind] == '0' && bin[ind + 1] == '1') {
        list[i].type = T_REG;
        list[i].size = 1;
        return 1;
    }
    return 0;
}

param_t *read_param(int len, char *bin)
{
    param_t *list = init_list(len);
    int ind = 0;
    int num = 0;

    for (int i = 0; i < len; i++) {
        num += fill_types(list, i, bin, ind);
        ind += 2;
    }
    list[len].type = 0;
    if (num != len) {
        free(list);
        return NULL;
    }
    return list;
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

int value_of_param(champ_t *champ, corewar_t *game, param_t list)
{
    int index = 0;

    if (list.type == T_REG)
        return champ->reg[list.value - 1];
    if (list.type == T_DIR) {
        return list.value;
    }
    index = (champ->pc + ((short)list.value % IDX_MOD));
    return read_int_from_memory(game, index);
}
