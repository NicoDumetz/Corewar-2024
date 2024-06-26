/*
** EPITECH PROJECT, 2024
** lld
** File description:
** lld
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void lld_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_lld(champ_t *champ, corewar_t *game, param_t *list)
{
    int reg = list[1].value;
    int index = 0;
    int value;

    if (reg - 1 > REG_NUMBER) {
        champ->carry = 0;
        return;
    }
    if (list[0].type == T_IND) {
        index = (champ->pc + (short)list[0].value);
        value = read_int_from_memory(game, index);
    } else
        value = list[0].value;
    champ->reg[reg - 1] = value;
    champ->carry = value == 0 ? 1 : 0;
}

void lld(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);
    param_t *list;

    list = read_param(2, bin);
    if (list == NULL || check_var_ld(list) == 1) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value(champ, game, list, 2);
    execute_lld(champ, game, list);
    lld_moove(champ, list, bin);
    return;
}
