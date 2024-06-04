/*
** EPITECH PROJECT, 2024
** add
** File description:
** add
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void add_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_add(champ_t *champ, param_t *list)
{
    int value = champ->reg[list[0].value - 1] +
    champ->reg[list[1].value - 1];

    champ->reg[list[2].value - 1] = value;
    champ->carry = value == 0 ? 1 : 0;
}

void add(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);
    param_t *list;

    list = read_param(3, bin);
    if (list == NULL || check_only_reg(list) == 1) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value(champ, game, list, 3);
    if (list[0].value - 1 <= REG_NUMBER && list[1].value - 1 <= REG_NUMBER &&
        list[2].value - 1 <= REG_NUMBER)
        execute_add(champ, list);
    else
        champ->carry = 0;
    add_moove(champ, list, bin);
    return;
}
