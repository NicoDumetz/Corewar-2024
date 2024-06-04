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
    write(2, "Wrong files, magic are not correct.\n",
    my_strlen("Wrong files, magic are not correct.\n"));
    return 84;
}

static void init_champ_game(champ_t *champ, int k)
{
    for (int i = 1; i < REG_NUMBER; i++)
        champ->reg[i] = 0;
    champ->carry = 0;
    champ->alive = 1;
    champ->cycle_die = 0;
    champ->index = k;
    champ->reg[0] = k;
}

int add_champs(char *filename, corewar_t *game, int i)
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
    champ->comment = str + 4 + PROG_NAME_LENGTH + 8;
    champ->all = str;
    champ->code = pick_bin(str, champ->prog_size);
    init_champ_game(champ, i);
    champ->next = game->list;
    game->list = champ;
    return 0;
}

int init_champ(int ac, char **av, corewar_t *game)
{
    if (ac < 2 || ac > 5)
        return 84;
    game->list = NULL;
    for (int i = 1; i < ac; i++) {
        if (add_champs(av[i], game, i) == 84)
            return 84;
    }
    return 0;
}

void destroy_allchamps(corewar_t *game)
{
    champ_t *champ = game->list;
    champ_t *prev = NULL;

    for (; champ; champ = champ->next) {
        if (champ->code)
            free(champ->code);
        if (prev)
            free(prev);
        if (champ->all)
            free(champ->all);
        prev = champ;
    }
    free(prev);
    return;
}
