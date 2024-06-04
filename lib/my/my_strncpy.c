/*
** EPITECH PROJECT, 2023
** my_strncpy
** File description:
** copy the n first elements of src list into dest
*/
#include "my.h"

char *my_strncpy(char *dest, char const *str, int n)
{
    int i;
    int end = 0;

    if (my_strlen(dest) < n) {
        end = 1;
    }
    for (i = 0; i < n; ++i) {
        dest[i] = str[i];
    }
    if (end) {
        dest[i] = '\0';
    }
    return (dest);
}
