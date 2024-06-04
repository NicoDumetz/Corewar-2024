/*
** EPITECH PROJECT, 2024
** B-CPE-200-LIL-2-1-robotfactory-matisse.dufour
** File description:
** board.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int get_board_size(char *str)
{
    FILE *fd;
    size_t len = 0;
    char *line = 0;
    int i = 0;

    fd = fopen(str, "r");
    for (; getline(&line, &len, fd) != -1; i++);
    free(line);
    fclose(fd);
    return i;
}

char *format_str(char *str)
{
    int i;
    int in_str = 0;

    for (i = 0; str[i]; i++) {
        in_str = (str[i] == 34) ? !in_str : in_str;
        if (str[i] == '\t' || str[i] == ',')
            str[i] = ' ';
        if (str[i] == '#' && in_str == 0) {
            str[i] = '\0';
            return str;
        }
    }
    if (str[my_strlen(str) - 1] == '\n')
        str[my_strlen(str) - 1] = '\0';
    return str;
}

void free_board(char ***command)
{
    for (int i = 0; command[i]; i++) {
        for (int j = 0; command[i][j]; j++)
            free(command[i][j]);
        free(command[i]);
    }
    free(command);
}

static int check_line(char **command, char **new_line, char *temp)
{
    int i;
    int j;
    int separator = 0;
    int len;

    for (i = 0; command[i + 1]; i++);
    for (j = 0; new_line[j]; j++);
    for (int k = 0; temp[k]; k++) {
        if (temp[k] == 34)
            separator += 1;
    }
    len = my_strlen(command[i]);
    if (command[i][len - 1] != 34 || j > 3 || separator != 2)
        return 1;
    return 0;
}

static void free_line(char **board)
{
    for (int i = 0; board[i]; i++)
        free(board[i]);
    free(board);
}

static void get_string(char **command, char *temp)
{
    char delimiter[] = {34, 0};
    char **new_line;
    int in_str = 0;

    for (int i = 0; temp[i]; i++) {
        in_str = (temp[i] == 34) ? !in_str : in_str;
        if (temp[i] == '#' && in_str == 0)
            temp[i] = '\0';
    }
    new_line = my_str_to_array(temp, delimiter);
    if (check_line(command, new_line, temp)) {
        for (int i = 1; command[i]; i++)
            free(command[i]);
        command[1] = 0;
        free_line(new_line);
    } else {
    free(command[1]);
    command[1] = my_strdup(new_line[1]);
    free_line(new_line);
    }
}

void assign_line(char ***command, char *str, int *i)
{
    char *temp = my_strdup(str);

    command[*i] = my_str_to_array(format_str(str), " ");
    if (command[*i][0] == 0) {
        free(temp);
        free(command[*i]);
        *i -= 1;
        return;
    }
    if (command[*i][1] != 0 && (my_strcmp(command[*i][0], ".name") == 0 ||
    my_strcmp(command[*i][0], ".comment") == 0)) {
        get_string(command[*i], temp);
    }
    free(temp);
}
