/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** concatenate the n first char of src at dest
*/
#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int start;
    int i;

    start = my_strlen(dest);
    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i + start] = src[i];
    }
    dest[start + i] = '\0';
    return dest;
}
