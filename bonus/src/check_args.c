/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** check_args.c
*/

#include <string.h>
#include "../include/corewar.h"
#include "stdbool.h"

static bool is_num(char *str)
{
    if (str[0] == '\0')
        return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

int check_flags(int argc, char **argv, corewar_t *game)
{
    game->dump = -1;
    if (argc < 2)
        return 84;
    if (my_strcmp(argv[1], "-dump"))
        return 0;
    if (!argv[2] || !is_num(argv[2]))
        return 84;
    game->dump = my_getnbr(argv[2]);
    return 0;
}
