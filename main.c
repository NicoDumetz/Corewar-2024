/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar
*/

#include "include/corewar.h"
#include "include/op.h"


void disp_champ(champ_t *c)
{
    printf("name : %s\nprog size = %d\ncomment = %s\n", c->name,
        c->prog_size, c->comment);
}

int main(int ac, char **av)
{
    corewar_t game;

    game.list = NULL;
    if (init_champ(ac, av, &game) == 84)
        return 84;
    return 0;
}
