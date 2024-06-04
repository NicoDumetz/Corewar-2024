/*
** EPITECH PROJECT, 2024
** sti
** File description:
** sti
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void sti_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_sti(champ_t *champ, corewar_t *game, param_t *list)
{
    int reg = list[0].value;
    int second = value_of_param(champ, game, list[1]);
    int third = value_of_param(champ, game, list[2]);
    int pc = champ->pc + ((third + second) % IDX_MOD);

    write_int_to_memory(champ->reg[reg - 1], game, pc, champ);
}

void sti(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);
    param_t *list = NULL;

    list = read_param_except(3, bin);
    if (list == NULL || list[0].type != T_REG || list[2].type == T_IND) {
        add_pc(champ, 1);
        free(bin);
        return;
    }
    fill_value_except(champ, game, list, 3);
    if (check_reg(list) == 0)
        execute_sti(champ, game, list);
    sti_moove(champ, list, bin);
    return;
}
