/*
** EPITECH PROJECT, 2024
** body
** File description:
** body command
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

int is_2bytes(char *instruction)
{
    return my_strcmp(instruction, "zjmp") == 0 ||
    my_strcmp(instruction, "ldi") == 0 ||
    my_strcmp(instruction, "sti") == 0 ||
    my_strcmp(instruction, "lldi") == 0 ||
    my_strcmp(instruction, "lfork") == 0 ||
    my_strcmp(instruction, "fork") == 0;
}

static int send_param_codbyte(char **command, FILE *file, int i)
{
    if (my_strcmp("live", command[i]) == 0 ||
        my_strcmp("fork", command[i]) == 0 ||
        my_strcmp("lfork", command[i]) == 0 ||
        my_strcmp("zjmp", command[i]) == 0)
        return 0;
    if (command[i + 2] == NULL)
        return write_codingbytes(command[i + 1], NULL, NULL, file);
    if (command[i + 3] == NULL)
        return write_codingbytes(command[i + 1], command[i + 2], NULL, file);
    return write_codingbytes(command[i + 1], command[i + 2],
    command[i + 3], file);
}

static int send_param(char ***command, FILE *file, int j, int first)
{
    for (int i = first + 1; command[j][i]; i++) {
        write_param(command, i, j, file);
    }
    return 0;
}

static void write_executable(char ***command, FILE *file, int j, int first)
{
    int change = 0;

    if (command[j] == NULL || command[j][1] == NULL)
        return;
    for (int p = 0; command[j][first][p]; p++)
        command[j][first][p] = command[j][first][p] == ',' ? '\0' :
        command[j][first][p];
    for (int i = 0; op_tab[i].comment; i++) {
        if (my_strcmp(op_tab[i].mnemonique, command[j][first]) == 0) {
            write_num_file(file, op_tab[i].code);
            send_param_codbyte(command[j], file, first);
            send_param(command, file, j, first);
            change = 1;
        }
    }
    if (change == 0)
        write_executable(command, file, j, first + 1);
}

int write_command(FILE *file, char ***command, int from)
{
    for (int j = from; command[j]; j++) {
        write_executable(command, file, j, 0);
    }
    return 0;
}
