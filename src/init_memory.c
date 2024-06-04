/*
** EPITECH PROJECT, 2024
** init memory
** File description:
** init memory
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


int len_hero(corewar_t *game)
{
    champ_t *champ = game->list;
    int nbr = 0;

    for (; champ; champ = champ->next)
        nbr++;
    return nbr;
}

void write_code_champ(corewar_t *game, int pos, champ_t *champ)
{
    for (int k = 0; k < champ->prog_size; k++) {
        if (pos == MEM_SIZE)
            pos = 0;
        game->board[pos] = champ->code[k];
        pos++;
    }
    return;
}

void init_memory(corewar_t *game)
{
    champ_t *champ = game->list;
    int div;
    int pos = 0;

    game->len_hero = len_hero(game);
    for (int i = 0; i < MEM_SIZE; i++)
        game->board[i] = 0;
    div = MEM_SIZE / game->len_hero + 1;
    for (; champ; champ = champ->next) {
        champ->pc = (int)pos;
        write_code_champ(game, champ->pc, champ);
        pos += div;
    }
}
