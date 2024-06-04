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
    champ->cycle_die--;
    command = which_command(champ, game);
    if (command == NULL) {
        if (champ->wait <= -1)
            add_pc(champ, 1);
        return;
    }
    for (int i = 0; com_tab[i].name; i++) {
        if (my_strcmp(command, com_tab[i].name) == 0)
            com_tab[i].com(champ, game);
    }
    return;
}

int game_loop(corewar_t *game)
{
    champ_t *champ = NULL;

    while (how_many_are_alive(game) > 1) {
        champ = game->list;
        for (; champ; champ = champ->next) {
            execute_champion(champ, game);
        }
        manage_cycle_to_die(game);
    }
    display_winner(game);
    return 0;
}
