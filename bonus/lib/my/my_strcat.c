/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** concatenate two strings
*/
#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int start;
    int i;

    start = my_strlen(dest);
    for (i = 0; src[i] != '\0'; i++) {
        dest[i + start] = src[i];
    }
    dest[start + i] = '\0';
    return dest;
}
