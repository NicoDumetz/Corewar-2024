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
        game->board[pos].c = champ->code[k];
        game->board[pos].index = champ->index;
        pos++;
    }
    return;
}

void init_memory(corewar_t *game)
{
    champ_t *champ = game->list;
    int div;
    int pos = 0;

    game->cycle_delta = CYCLE_DELTA;
    game->cycle_die = CYCLE_TO_DIE;
    game->len_hero = len_hero(game);
    game->nbr_live = 0;
    game->last_name = NULL;
    game->last_index = 0;
    for (int i = 0; i < MEM_SIZE; i++) {
        game->board[i].c = 0;
        game->board[i].index = -1;
    }
    div = MEM_SIZE / game->len_hero + 1;
    for (; champ; champ = champ->next) {
        champ->pc = (int)pos;
        write_code_champ(game, champ->pc, champ);
        pos += div;
    }
}
