/*
** EPITECH PROJECT, 2024
** game_loop
** File description:
** game_loop
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

void add_pc(champ_t *champ, int nbr)
{
    for (int i = 0; i < nbr; i++) {
        champ->pc++;
        if (champ->pc >= MEM_SIZE)
            champ->pc = 0;
        if (champ->pc < 0)
            champ->pc = MEM_SIZE;
    }
}

char *which_command(champ_t *champ, corewar_t *game)
{
    for (int i = 0; op_tab[i].code; i++) {
        if (game->board[champ->pc] == op_tab[i].code && champ->wait == 0)
            return op_tab[i].mnemonique;
        if (game->board[champ->pc] == op_tab[i].code && champ->wait <= -1) {
            champ->wait = op_tab[i].nbr_cycles - 1;
            return NULL;
        }
    }
    return NULL;
}

void execute_champion(champ_t *champ, corewar_t *game)
{
    char *command = NULL;

    champ->wait--;
    if (champ->alive == 0)
        return;
    command = which_command(champ, game);
    if (command == NULL) {
        if (champ->wait <= -1)
            add_pc(champ, 1);
        return;
    }
    add_pc(champ, 1);
    return;
}

int game_loop(corewar_t *game)
{
    champ_t *champ = NULL;

    //while (how_many_are_alive(game) > 1) { en attendant le dump
    for (int i = 0; i < 50; i++) {
        champ = game->list;
        for (; champ; champ = champ->next) {
            execute_champion(champ, game);
        }
    }
    return 0;
}
