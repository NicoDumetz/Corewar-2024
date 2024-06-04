/*
** EPITECH PROJECT, 2024
** ldi
** File description:
** ldi
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void ldi_moove(champ_t *champ, param_t *list, char *bin)
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

static void execute_ldi(champ_t *champ, corewar_t *game, param_t *list)
{
    int first = value_of_param(champ, game, list[0]);
    int second = value_of_param(champ, game, list[1]);
    int reg = list[2].value;
    int pc = first + second;
    unsigned int value = read_int_from_memory(game, pc);

    champ->reg[reg - 1] = value;
    champ->carry = value == 0 ? 1 : 0;
}

void ldi(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param_except(3, bin);
    if (list == NULL) {
        add_pc(champ, 1);
        return;
    }
    fill_value_except(champ, game, list, 3);
    execute_ldi(champ, game, list);
    ldi_moove(champ, list, bin);
    return;
}
