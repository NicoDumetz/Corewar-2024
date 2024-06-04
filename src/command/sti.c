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
    my_printf("sti %s\n", champ->name);
    add_pc(champ, add + 2);
    free(list);
    free(bin);
    return;
}

void sti(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list;

    list = read_param(3, bin);
    sti_moove(champ, list, bin);
    return;
}
