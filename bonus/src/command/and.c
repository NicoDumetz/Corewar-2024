/*
** EPITECH PROJECT, 2024
** and
** File description:
** and
*/

#include "../../include/corewar.h"
#include "../../include/op.h"
#include "../../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void and_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_and(champ_t *champ, corewar_t *game, param_t *list)
{
    int first = value_of_param(champ, game, list[0]);
    int second = value_of_param(champ, game, list[1]);
    int reg = list[2].value;
    int res = first & second;

    champ->reg[reg - 1] = res;
    champ->carry = res == 0 ? 1 : 0;
}

void and_cor(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);
    param_t *list;

    list = read_param(3, bin);
    if (list == NULL || list[2].type != T_REG) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value(champ, game, list, 3);
    if (check_reg(list) == 0)
        execute_and(champ, game, list);
    else
        champ->carry = 0;
    and_moove(champ, list, bin);
    return;
}
