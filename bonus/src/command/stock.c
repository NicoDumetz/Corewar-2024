/*
** EPITECH PROJECT, 2024
** st
** File description:
** s
*/

/*
** EPITECH PROJECT, 2024
** load
** File description:
** load
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void stock_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_st(champ_t *champ, corewar_t *game, param_t *list)
{
    int value = list[0].value - 1;
    int index = 0;

    if (value > REG_NUMBER)
        return;
    value = champ->reg[list[0].value - 1];
    if (list[1].type == T_REG) {
        if (list[1].value - 1 > REG_NUMBER)
            return;
        champ->reg[list[1].value - 1] = value;
    } else {
        index = (champ->pc + ((short)list[1].value % IDX_MOD));
        write_int_to_memory(value, game, index, champ);
    }
    return;
}

static int check_var_st(param_t *list)
{
    if (list[0].type != T_REG) {
        free(list);
        return 1;
    }
    if (list[1].type == T_DIR) {
        free(list);
        return 1;
    }
    return 0;
}

void stock(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);
    param_t *list;

    list = read_param(2, bin);
    if (list == NULL || check_var_st(list) == 1) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value(champ, game, list, 2);
    execute_st(champ, game, list);
    stock_moove(champ, list, bin);
    return;
}
