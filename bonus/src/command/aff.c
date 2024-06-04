/*
** EPITECH PROJECT, 2024
** aff
** File description:
** aff
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


static void execute_aff(champ_t *champ, corewar_t *game)
{
    int reg = game->board[champ->pc + 2].c;

    if (reg > 16 || reg <= 0)
        return;
    if (champ->reg[reg] != 0)
        my_printf("%c\n", champ->reg[reg]);
}

void aff(champ_t *champ, corewar_t *game)
{
    int pc = champ->pc + 1;
    char *bin = dec_to_octet(game->board[pc].c, "01", 8);

    if (my_strcmp(bin, "01000000") == 0)
        execute_aff(champ, game);
    add_pc(champ, 3);
    free(bin);
    return;
}
