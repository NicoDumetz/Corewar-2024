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
    my_printf("ADD %s\n", champ->name);
    add_pc(champ, add + 2);
    free(list);
    free(bin);
    return;
}

static void execute_add(champ_t *champ, param_t *list)
{
    int value = champ->reg[list[0].value] + champ->reg[list[1].value];

    champ->reg[list[2].value] = value;
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
