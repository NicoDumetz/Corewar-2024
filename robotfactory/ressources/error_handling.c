/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-matisse.dufour
** File description:
** error_handling.c
*/

#include "asm.h"
#include "my.h"
#include "op.h"

static int header_line_error(char **line, int max_length, char *command)
{
    if (line[0] == 0)
        return 1;
    if (line[1] == 0)
        return 1;
    if (my_strlen(line[1]) > max_length)
        return 1;
    if (my_strcmp(line[0], command) != 0)
        return 1;
    return 0;
}

static int header_error(char ***command, int *k)
{
    int i = 0;

    for (; command[i] != 0; i++);
    if (i < 1) {
        write(2, "File empty\n", 11);
        return 1;
    }
    if (header_line_error(command[0], PROG_NAME_LENGTH, ".name")) {
        write(2, "asm: Error in name\n", 19);
        return 1;
    }
    *k = 1;
    if (command[1] == 0)
        return 0;
    if (header_line_error(command[1], COMMENT_LENGTH, ".comment"))
        write(2, "Warning: No comment or comment error\n", 37);
    else
        *k += 1;
    return 0;
}

static int label_check(char *str, char ***command, int k)
{
    int j = 0;
    int len = my_strlen(str) - 1;

    if (len == 0)
        return 1;
    for (int i = 0; i < len; i++) {
        if (LABEL_CHARS[j] == '\0')
            return 1;
        if (str[i] == LABEL_CHARS[j]) {
            j = 0;
            continue;
        }
        if (str[i] != LABEL_CHARS[j])
            i--;
        j++;
    }
    for (j = 0; j < k && my_strcmp(command[j][0], str) != 0; j++);
    return (j == k) ? 0 : 1;
}

static int is_a_num(char *str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;
    for (; '0' <= str[i] && str[i] <= '9'; i++);
    if (str[i] == '\0')
        return 1;
    return 0;
}

static int value_or_label(char ***command, char *arg)
{
    int nb;
    int len_arg = my_strlen(arg) - 1;

    if (arg[0] != LABEL_CHAR) {
        if (!is_a_num(arg))
            return 0;
        return 1;
    }
    for (nb = 0; command[nb]; nb++) {
        if (my_strncmp(command[nb][0], arg + 1, len_arg) == 0 &&
        command[nb][0][len_arg] == LABEL_CHAR)
            return 1;
    }
    return 0;
}

static int get_arg_type(char ***command, char *arg)
{
    int nb;

    if (arg[0] == 'r') {
        nb = my_getnbr(arg + 1);
        if (is_a_num(arg + 1) && nb >= 1 && nb <= REG_NUMBER)
            return T_REG;
        return 0;
    }
    if (arg[0] == DIRECT_CHAR) {
        if (value_or_label(command, arg + 1))
            return T_DIR;
        return 0;
    }
    if (value_or_label(command, arg))
        return T_IND;
    return 0;
}

static int check_args(char ***command, int i, int k, op_t *parameter)
{
    int nb_arg = 0;
    char type;

    for (; command[i][k + 1 + nb_arg]; nb_arg++);
    if (nb_arg != parameter->nbr_args) {
        write(2, "Wrong number of args\n", 21);
        return 1;
    }
    nb_arg = 0;
    for (k++; command[i][k + nb_arg]; nb_arg++) {
        type = get_arg_type(command, command[i][k + nb_arg]);
        if (type == 0 || !(type & parameter->type[nb_arg])) {
            write(2, "Wrong arg type\n", 15);
            return 1;
        }
    }
    return 0;
}

static int check_line(char ***command, int i)
{
    int j = 0;
    int k = 0;

    if (command[i][k][my_strlen(command[i][k]) - 1] == ':') {
        if (label_check(command[i][k], command, i)) {
            write(2, "Wrong label name\n", 17);
            return 1;
        }
        k++;
    }
    if (command[i][k] == 0)
        return 0;
    for (; op_tab[j].mnemonique &&
    my_strcmp(command[i][k], op_tab[j].mnemonique) != 0; j++);
    if (op_tab[j].mnemonique == 0) {
        write(2, "Non valid command\n", 18);
        return 1;
    }
    return (check_args(command, i, k, &op_tab[j])) ? 1 : 0;
}

static void write_line(char **line)
{
    write(2, "Error at Line: ", 15);
    for (int i = 0; line[i]; i++) {
        write(2, line[i], my_strlen(line[i]));
        write(2, " ", 1);
    }
    write(2, "\n", 1);
}

int errors_handling(char ***command, int *from)
{
    int i;

    if (header_error(command, &i))
        return 1;
    *from = i;
    for (; command[i]; i++) {
        if (check_line(command, i)) {
            write_line(command[i]);
            return 1;
        }
    }
    return 0;
}
