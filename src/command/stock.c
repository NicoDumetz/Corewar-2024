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
    int value = champ->reg[list[0].value - 1];
    int index = 0;

    if (list[1].type == T_REG)
        champ->reg[list[1].value - 1] = value;
    else {
        index = (champ->pc + list[1].value) % IDX_MOD;
        game->board[index] = value;
    }
    return;
}

void stock(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param(2, bin);
    fill_value(champ, game, list, 2);
    execute_st(champ, game, list);
    stock_moove(champ, list, bin);
    return;
}
