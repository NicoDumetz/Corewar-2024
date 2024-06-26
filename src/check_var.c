/*
** EPITECH PROJECT, 2024
** check_var
** File description:
** check_var
*/


#include "../include/corewar.h"
#include "../include/op.h"
#include "../include/my.h"
#include "stddef.h"
#include <sys/stat.h>
#include <string.h>

int check_only_reg(param_t *list)
{
    for (int i = 0; i < 3; i++) {
        if (list[i].type != T_REG) {
            free(list);
            return 1;
        }
    }
    return 0;
}

int check_reg(param_t *list)
{
    if (list[0].type == T_REG && list[0].value - 1 > REG_NUMBER)
        return 1;
    if (list[1].type == T_REG && list[1].value - 1 > REG_NUMBER)
        return 1;
    if (list[2].type == T_REG && list[2].value - 1 > REG_NUMBER)
        return 1;
    return 0;
}

int fill_types_except(param_t *list, int i, char *bin, int ind)
{
    if (bin[ind] == '1' && bin[ind + 1] == '0') {
        list[i].type = T_DIR;
        list[i].size = 2;
        return 1;
    }
    if (bin[ind] == '1' && bin[ind + 1] == '1') {
        list[i].type = T_IND;
        list[i].size = 2;
        return 1;
    }
    if (bin[ind] == '0' && bin[ind + 1] == '1') {
        list[i].type = T_REG;
        list[i].size = 1;
        return 1;
    }
    return 0;
}
