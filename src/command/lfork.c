/*
** EPITECH PROJECT, 2024
** lfork
** File description:
** lfork
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void lfork_moove(champ_t *champ, param_t *list, char *bin)
{
    my_printf("lfork %s\n", champ->name);
    add_pc(champ, 3);
    if (list != NULL)
        free(list);
    free(bin);
    return;
}

void lfork_cor(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc], "01", 8);
    param_t *list = NULL;

    lfork_moove(champ, list, bin);
    return;
}
