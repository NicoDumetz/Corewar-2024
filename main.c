/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar
*/

#include "include/corewar.h"
#include "include/op.h"

int main(int ac, char **av)
{
    corewar_t game;

    if (init_champ(ac, av, &game) == 84)
        return 84;
    init_memory(&game);
    game_loop(&game);
    destroy_allchamps(&game);
    return 0;
}
