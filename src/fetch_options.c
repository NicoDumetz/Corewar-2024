/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-corewar-matisse.dufour
** File description:
** fetch_options.c
*/

#include "corewar.h"
#include "errors.h"
#include "op.h"
#include <unistd.h>

static void print_num(int size)
{
    int len = 1;
    char c;

    if (size == 0) {
        write(2, "0", 1);
        return;
    }
    for (; (size / len) > 0; len *= 10);
    len /= 10;
    for (; len >= 1; len /= 10) {
        c = (size / len) + '0';
        size %= len;
        write(2, &c, 1);
    }
}

static int write_error(char *str1, char *str2, int size)
{
    if (str1)
        write(2, str1, my_strlen(str1));
    if (str2)
        write(2, str2, my_strlen(str2));
    print_num(size);
    write(2, "\n", 1);
    return 1;
}

static int set_pc(char *opt, champ_t *new)
{
    if (new->pc != -1)
        return write(2, MULTIPLE_PC, my_strlen(MULTIPLE_PC));
    if (!opt || !is_num(opt))
        return write_error(PC_VALUE1, PC_VALUE2, MEM_SIZE);
    new->pc = my_getnbr(opt);
    if (new->pc >= MEM_SIZE || new->pc < 0)
        return write_error(PC_VALUE1, PC_VALUE2, MEM_SIZE);
    return 0;
}

static bool already_defined(int index, corewar_t *game)
{
    for (champ_t *current = game->list; current; current = current->next) {
        if (current->index == index)
            return true;
    }
    return false;
}

static int set_index(char *opt, champ_t *new, corewar_t *game)
{
    if (new->index != -1)
        return write(2, MULTIPLE_INDEX_DEF, my_strlen(MULTIPLE_INDEX_DEF));
    if (!opt || !is_num(opt))
        return write(2, INDEX_VALUE, my_strlen(INDEX_VALUE));
    new->index = my_getnbr(opt);
    if (new->index < 1 || new->index > 4)
        return write(2, INDEX_VALUE, my_strlen(INDEX_VALUE));
    if (already_defined(new->index, game))
        return write(2, SAME_INDEX, my_strlen(SAME_INDEX));
    return 0;
}

int fetch_options(char **argv, unsigned char *i, champ_t *new, corewar_t *game)
{
    if (my_strcmp(argv[*i], "-a") && my_strcmp(argv[*i], "-n"))
        return 0;
    if (argv[*i][1] == 'a') {
        if (set_pc(argv[*i + 1], new))
            return 1;
    } else if (argv[*i][1] == 'n' && set_index(argv[*i + 1], new, game))
        return 1;
    *i += 2;
    if (argv[*i] == NULL)
        return write(2, ARGS_WITHOUT_CHAMP, my_strlen(ARGS_WITHOUT_CHAMP));
    return fetch_options(argv, i, new, game);
}
