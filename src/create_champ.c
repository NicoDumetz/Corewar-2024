/*
** EPITECH PROJECT, 2024
** create champ
** File description:
** create champ
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>

static char *close_dir(int fd)
{
    close(fd);
    return NULL;
}

char *read_file(const char *filename)
{
    struct stat file;
    int fd = open(filename, O_RDONLY);
    char *content;
    ssize_t bytes;

    if (stat(filename, &file) == -1 || fd == -1)
        return NULL;
    if (file.st_size < 4)
        return NULL;
    content = (char *)malloc(file.st_size + 1);
    if (content == NULL)
        return close_dir(fd);
    bytes = read(fd, content, file.st_size);
    if (bytes == -1) {
        free(content);
        return close_dir(fd);
    }
    content[file.st_size] = '\0';
    close(fd);
    return content;
}

static char *pick_bin(char *str, int size)
{
    char *code = malloc(sizeof(char) * (size + 1));
    int i = 4 + PROG_NAME_LENGTH + 4 + COMMENT_LENGTH + 8;

    for (int k = 0; k < size; k++) {
        code[k] = str[i];
        i++;
    }
    code[size] = '\0';
    return code;
}

static int check_magic(char *str)
{
    if (str[0] == 0 && str[1] == -22 && str[2] == -125 && str[3] == -13)
        return 0;
    return 84;
}

int add_champs(char *filename, corewar_t *game)
{
    char *str = read_file(filename);
    champ_t *champ = malloc(sizeof(champ_t));
    union intconverter converter;

    if (champ == NULL || str == NULL || check_magic(str) == 84)
        return 84;
    converter.bytes[0] = str[4 + PROG_NAME_LENGTH + 7];
    converter.bytes[1] = str[4 + PROG_NAME_LENGTH + 6];
    converter.bytes[2] = str[4 + PROG_NAME_LENGTH + 5];
    converter.bytes[3] = str[4 + PROG_NAME_LENGTH + 4];
    champ->name = str + 4;
    champ->prog_size = converter.value;
    champ->filename = filename;
    champ->comment = str + 4 + PROG_NAME_LENGTH + 7;
    champ->code = pick_bin(str, champ->prog_size);
    champ->next = game->list;
    game->list = champ;
    return 0;
}

int init_champ(int ac, char **av, corewar_t *game)
{
    if (ac < 2 || ac > 4)
        return 84;
    for (int i = 1; i < ac; i++) {
        if (add_champs(av[i], game) == 84)
            return 84;
    }
    return 0;
}
