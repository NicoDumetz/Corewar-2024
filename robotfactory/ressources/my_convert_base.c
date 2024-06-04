/*
** EPITECH PROJECT, 2023
** my_convert_base
** File description:
** convert a number given in a given base into
** another given base
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

static char *my_revstr_convert(char *str)
{
    int index;
    int len = my_strlen(str) - 1;
    char temp;

    for (index = 0; index < len; index++) {
        temp = str[index];
        str[index] = str[len];
        str[len] = temp;
        len--;
    }
    return str;
}

char *my_convert(unsigned long nb, char *base)
{
    int len = my_strlen(base);
    char res[30000];
    int index;

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return my_revstr_convert(res);
    }
    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    return my_revstr_convert(res);
}

int bin_to_dec(const char *bin)
{
    int dec = 0;
    int len = my_strlen(bin);

    for (int i = 0; i < len; i++)
        dec = dec * 2 + (bin[i] - '0');
    return dec;
}
