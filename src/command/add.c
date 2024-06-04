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
    unsigned int value = champ->reg[list[0].value - 1] +
    champ->reg[list[1].value - 1];

    champ->reg[list[2].value - 1] = value;
    champ->carry = value == 0 ? 1 : 0;
}

void add(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param(3, bin);
    fill_value(champ, game, list, 3);
    execute_add(champ, list);
    add_moove(champ, list, bin);
    return;
}
