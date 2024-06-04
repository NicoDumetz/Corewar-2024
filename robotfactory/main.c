/*
** EPITECH PROJECT, 2024
** main
** File description:
** main robotfactory
*/
#include "asm.h"
#include "include/my.h"
#include "include/op.h"
#include "lib/my/my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

static int file_errors(int ac, char **av, FILE **fd)
{
    if (ac != 2)
        return 1;
    *fd = fopen(av[1], "r");
    if (*fd == 0)
        return 1;
    return 0;
}

static int init_ressources(int ac, char **av, char ****command)
{
    char *str = 0;
    size_t len = 0;
    FILE *fd;
    int i = 0;

    if (file_errors(ac, av, &fd)) {
        write(2, "error init\n", 11);
        return 1;
    }
    *command = malloc(sizeof(char **) * (get_board_size(av[1]) + 1));
    for (; getline(&str, &len, fd) != -1; ++i)
        assign_line(*command, str, &i);
    (*command)[i] = 0;
    if (str)
        free(str);
    fclose(fd);
    return 0;
}

int main(int ac, char **av)
{
    char ***command;
    FILE *file;
    int size;
    int from;

    if (init_ressources(ac, av, &command))
        return 84;
    if (errors_handling(command, &from)) {
        free_board(command);
        return 84;
    }
    size = get_size(command, from);
    file = write_header(command[0], command[1], av[1], size);
    if (file == NULL && write(2, "error open file\n", 16) > 0)
        return 84;
    write_command(file, command, from);
    fclose(file);
    free_board(command);
    return 0;
}
