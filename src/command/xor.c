/*
** EPITECH PROJECT, 2024
** xor
** File description:
** xor
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void xor_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_xor(champ_t *champ, corewar_t *game, param_t *list)
{
    int first = value_of_param(champ, game, list[0]);
    int second = value_of_param(champ, game, list[1]);
    int reg = list[2].value;
    unsigned int res = first ^ second;

    champ->reg[reg - 1] = res;
    champ->carry = res == 0 ? 1 : 0;
}

void xor_cor(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param(3, bin);
    fill_value(champ, game, list, 3);
    execute_xor(champ, game, list);
    xor_moove(champ, list, bin);
    return;
}
