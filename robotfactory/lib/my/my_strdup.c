/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** duplicate and return a string terminated by \0
** it's at the programmer to free the returned str
*/
#include "my.h"
#include <stdlib.h>

char *my_strdup(const char *src)
{
    int size;
    char *dest;

    size = my_strlen(src) + 1;
    dest = malloc(size);
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[size - 1] = '\0';
    return dest;
}
