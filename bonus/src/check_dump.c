/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** check_args.c
*/

#include <string.h>
#include "corewar.h"
#include "stdbool.h"
#include "errors.h"

bool is_num(char *str)
{
    if (str[0] == '\0')
        return false;
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return false;
    }
    return true;
}

static void remove_dump_args(char **argv, unsigned char i)
{
    free(argv[i]);
    free(argv[i + 1]);
    for (; argv[i + 1]; i++)
        argv[i] = argv[i + 2];
}

int check_dump(char **argv, corewar_t *game)
{
    game->dump = -1;
    for (unsigned int i = 0; argv[i]; i++) {
        if (my_strcmp(argv[i], "-dump"))
            continue;
        if (game->dump != -1)
            return write(2, MULTIPLE_DUMP, my_strlen(MULTIPLE_DUMP));
        if (!argv[i + 1] || !is_num(argv[i + 1]))
            return write(2, DUMP_VALUE, my_strlen(DUMP_VALUE));
        game->dump = my_getnbr(argv[i + 1]);
        if (game->dump < 0)
            return write(2, DUMP_VALUE, my_strlen(DUMP_VALUE));
        remove_dump_args(argv, i);
        i -= 1;
    }
    return 0;
}
