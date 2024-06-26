/*
** EPITECH PROJECT, 2024
** decimal to octet
** File description:
** decimal to octet
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
