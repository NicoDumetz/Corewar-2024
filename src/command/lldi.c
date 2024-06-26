/*
** EPITECH PROJECT, 2024
** lldi
** File description:
** lldi
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void lldi_moove(champ_t *champ, param_t *list, char *bin)
{
    int add = 0;

    for (int i = 0; list[i].type != 0; i++) {
        add += list[i].size;
    }
    add_pc(champ, add + 2);
    free(list);
    free(bin);
    return;
}

int value_of_param_for_lldi(champ_t *champ, corewar_t *game, param_t list)
{
    int index = 0;
    union intconverter converter;

    if (list.type == T_REG)
        return champ->reg[list.value - 1];
    if (list.type == T_DIR) {
        return list.value;
    }
    converter.bytes[0] = game->board[(index + 1) % MEM_SIZE];
    converter.bytes[1] = game->board[(index) % MEM_SIZE];
    converter.bytes[2] = 0;
    converter.bytes[3] = 0;
    return converter.value;
}

static void execute_lldi(champ_t *champ, corewar_t *game, param_t *list)
{
    int first = value_of_param_for_lldi(champ, game, list[0]);
    int second = value_of_param(champ, game, list[1]);
    int reg = list[2].value;
    int pc = champ->pc + ((first + second) % IDX_MOD);
    int value = read_int_from_memory(game, pc);

    champ->reg[reg - 1] = value;
    champ->carry = value == 0 ? 1 : 0;
}

void lldi(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param(3, bin);
    if (list == NULL || list[2].type != T_REG || list[1].type == T_IND) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value_except(champ, game, list, 3);
    if (check_reg(list) == 0)
        execute_lldi(champ, game, list);
    else
        champ->carry = 0;
    lldi_moove(champ, list, bin);
    return;
}
