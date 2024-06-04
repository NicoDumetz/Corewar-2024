/*
** EPITECH PROJECT, 2024
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include "my.h"
#include "errors.h"
#include <stdlib.h>

int free_tab(char **argv, int return_value)
{
    for (unsigned char i = 0; argv[i]; i++)
        free(argv[i]);
    free(argv);
    return return_value;
}

static char **copy_argv(int ac, char **argv)
{
    char **copy = NULL;

    if (ac > 15) {
        write(2, TO_MANY_ARGS, my_strlen(TO_MANY_ARGS));
        return NULL;
    }
    copy = malloc((ac + 1) * sizeof(char *));
    if (copy == NULL)
        return NULL;
    for (unsigned char i = 0; i <= ac; i++)
        copy[i] = 0;
    for (unsigned char i = 0; argv[i]; i++) {
        copy[i] = my_strdup(argv[i]);
        if (copy[i] == NULL) {
            free_tab(copy, 0);
            return NULL;
        }
    }
    return copy;
}

int main(int ac, char **av)
{
    corewar_t game;

    av = copy_argv(ac, av);
    if (av == NULL)
        return 84;
    if (check_dump(av, &game))
        return free_tab(av, 84);
    if (init_champ(ac, av, &game) == 84)
        return 84;
    init_memory(&game);
    game_loop(&game);
    destroy_allchamps(&game);
    return 0;
}
