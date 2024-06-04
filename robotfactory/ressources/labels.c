/*
** EPITECH PROJECT, 2024
** labels
** File description:
** manage labels
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

static int check_type_size(char ***command, int k, int p)
{
    if (command[k][p][0] == 'r' && my_getnbr(command[k][p] + 1) != 0)
        return 1;
    if (command[k][p][0] == '%' && (is_2bytes(command[k][0]) ||
        is_2bytes(command[k][1])))
        return 2;
    if (command[k][p][0] == '%')
        return 4;
    if ((command[k][p][0] >= '0' && command[k][p][0] <= '9') ||
        command[k][p][0] == '-')
        return 2;
    if (command[k][p][my_strlen(command[k][p]) - 1] == ':')
        return 0;
    if (my_strcmp("live", command[k][p]) == 0 ||
        my_strcmp("fork", command[k][p]) == 0 ||
        my_strcmp("lfork", command[k][p]) == 0 ||
        my_strcmp("zjmp", command[k][p]) == 0)
        return 1;
    else
        return 2;
}

int reverse_labels(char ***command, int i, int j, int dec)
{
    char *label = command[j][i] + dec;
    int bytes = 0;
    int k;
    int p;

    for (k = j - 1; command[k] && command[k][0]; k--) {
        for (p = 0; command[k][p]; p++) {
            bytes -= check_type_size(command, k, p);
        }
        if (my_strncmp(label, command[k][0], my_strlen(label)) == 0 &&
            my_strlen(label) == my_strlen(command[k][0]) - 1 &&
            command[k][0][my_strlen(command[k][0]) - 1] == ':') {
            break;
        }
    }
    return bytes;
}

int manage_labels(char ***command, int i, int j, int dec)
{
    char *label = command[j][i] + dec;
    int count = 0;
    int bytes = 0;
    int k;

    for (k = j; command[k] && command[k][0]; k++) {
        if (my_strncmp(label, command[k][0], my_strlen(label)) == 0 &&
            my_strlen(label) == my_strlen(command[k][0]) - 1 &&
            command[k][0][my_strlen(command[k][0]) - 1] == ':') {
            count = 1;
            break;
        }
        for (int p = 0; command[k][p]; p++)
            bytes += check_type_size(command, k, p);
    }
    if (count == 0)
        return reverse_labels(command, i, j, dec);
    return bytes;
}

int print_labels(char ***command, int i, int j, FILE *file)
{
    int bytes = manage_labels(command, i, j, 2);
    short reg_short = (short)bytes;

    if (is_2bytes(command[j][0]) || is_2bytes(command[j][1])) {
        reverse_bytes_int((uint8_t *)&reg_short, sizeof(reg_short));
        fwrite(&reg_short, sizeof(reg_short), 1, file);
    } else {
        reverse_bytes_int((uint8_t *)&bytes, sizeof(bytes));
        fwrite(&bytes, sizeof(bytes), 1, file);
    }
    return 0;
}

int get_size(char ***command, int from)
{
    int bytes = 0;
    int k;

    for (k = from; command[k]; k++) {
        for (int p = 0; command[k][p]; p++) {
            bytes += check_type_size(command, k, p);
        }
    }
    return bytes;
}
