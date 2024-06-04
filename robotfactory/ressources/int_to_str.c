/*
** EPITECH PROJECT, 2024
** int to str
** File description:
** int to str
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

char *int_to_str(int nb)
{
    char *buffer = malloc(100);
    int i = 0;

    if (nb == 0) {
        buffer[i] = '0';
        i++;
    } else {
        for (i = 0; nb != 0 && i < 100; i++) {
            buffer[i] = '0' + nb % 10;
            nb /= 10;
        }
    }
    buffer[i] = '\0';
    return my_revstr_convert(buffer);
}
