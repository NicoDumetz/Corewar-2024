/*
** EPITECH PROJECT, 2024
** create champ
** File description:
** create champ
*/

#include "corewar.h"
#include "op.h"
#include "my.h"
#include "errors.h"
#include "stddef.h"
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

static char *read_errors(int fd, char const *filename, char *error_message)
{
    if (filename) {
        write(2, filename, my_strlen(filename));
        write(2, ": ", 2);
    }
    if (error_message)
        write(2, error_message, my_strlen(error_message));
    if (fd > 0)
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
        return read_errors(0, filename, OPEN_FILE);
    if (file.st_size < 4)
        return read_errors(0, filename, WRONG_MAGIC);
    content = (char *)malloc(file.st_size + 1);
    if (content == NULL)
        return read_errors(fd, 0, 0);
    bytes = read(fd, content, file.st_size);
    if (bytes == -1) {
        free(content);
        return read_errors(fd, 0, 0);
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

static int check_magic(char *str, char *filename)
{
    if (str[0] == 0 && str[1] == -22 && str[2] == -125 && str[3] == -13)
        return 0;
    free(str);
    read_errors(0, filename, WRONG_MAGIC);
    return 84;
}

static bool check_champ(corewar_t *game, int *error)
{
    int champ_nb = 0;

    for (champ_t *current = game->list; current; current = current->next) {
        if (!((current->index >= 1 && current->index <= 4) ||
        current->index == -1))
            return true;
        champ_nb++;
    }
    if (champ_nb > 4) {
        write(2, TOO_MANY_CHAMP, my_strlen(TOO_MANY_CHAMP));
        *error = 1;
        return true;
    }
    if (champ_nb < 2) {
        write(2, NOT_ENOUGH_CHAMP, my_strlen(NOT_ENOUGH_CHAMP));
        *error = 1;
        return true;
    }
    return false;
}

static void set_index(corewar_t *game)
{
    bool taken_index[4] = {false, false, false, false};
    int index;

    for (champ_t *current = game->list; current; current = current->next) {
        if (current->index != -1)
            taken_index[current->index - 1] = true;
    }
    for (champ_t *current = game->list; current; current = game->list) {
        if (current->index != -1)
            return;
        for (index = 0; taken_index[index] && index < 4; index++);
        current->index = index + 1;
        current->reg[0] = current->index;
        taken_index[index] = true;
        game->list = current->next;
        insert_champ(current, game);
    }
}

static void init_champ_game(champ_t *champ)
{
    for (int i = 1; i < REG_NUMBER; i++)
        champ->reg[i] = 0;
    champ->carry = 0;
    champ->alive = 1;
    champ->cycle_die = CYCLE_TO_DIE;
    champ->reg[0] = champ->index;
    champ->wait = -1;
}

int add_champs(char *filename, champ_t *champ, corewar_t *game)
{
    char *str = read_file(filename);
    union intconverter converter;

    if (champ == NULL || str == NULL || check_magic(str, filename) == 84)
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
    init_champ_game(champ);
    insert_champ(champ, game);
    return 0;
}

int init_champ(char **av, corewar_t *game)
{
    champ_t *new = NULL;
    int error = 0;

    game->list = NULL;
    for (unsigned char i = 1; av[i] && !error; i++) {
        new = malloc(sizeof(champ_t));
        if (new == NULL)
            return 1;
        new->pc = -1;
        new->index = -1;
        if (fetch_options(av, &i, new, game) || add_champs(av[i], new, game)) {
            error = 1;
            free(new);
        }
    }
    if (error || check_champ(game, &error))
        destroy_allchamps(game);
    else
        set_index(game);
    return free_tab(av, error);
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
