/*
** EPITECH PROJECT, 2023
** gigogd
** File description:
** ouaoi
*/
#include "my.h"

int my_showstr(char const *str)
{
    int taille;

    taille = my_strlen(str);
    if (taille > 2) {
        return 0;
    }
    return 1;
}
