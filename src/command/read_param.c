/*
** EPITECH PROJECT, 2024
** read_param
** File description:
** read_param
*/

#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>


char *dec_to_octet(unsigned long nb, char *base, int size)
{
    int len = my_strlen(base);
    char *res = (char *)malloc(size + 1);
    int index;

    for (int i = 0; i < size; i++)
        res[i] = '0';
    res[size] = '\0';
    if (nb == 0) {
        res[size - 1] = '0';
        return res;
    }
    for (index = size - 1; nb > 0 && index >= 0; index--) {
        res[index] = base[nb % len];
        nb /= len;
    }
    return res;
}

void reset_dir(param_t *list)
{
    for (int i = 0; list[i].type != 0; i++) {
        if (list[i].size == 4)
            list[i].size = 2;
    }
}

param_t *read_param(int len, char *bin)
{
    param_t *list = malloc(sizeof(param_t) * (len + 1));
    int ind = 0;

    for (int i = 0; i < len; i++) {
        if (bin[ind] == '1' && bin[ind + 1] == '0') {
            list[i].type = T_DIR;
            list[i].size = 4;
        }
        if (bin[ind] == '1' && bin[ind + 1] == '1') {
            list[i].type = T_IND;
            list[i].size = 2;
        }
        if (bin[ind] == '0' && bin[ind + 1] == '1') {
            list[i].type = T_DIR;
            list[i].size = 1;
        }
        ind += 2;
    }
    list[len].type = 0;
    return list;
}
