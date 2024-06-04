/*
** EPITECH PROJECT, 2023
** void header
** File description:
** hrfhurf
*/
#include "my.h"

int my_showmem(char const *str, int size)
{
    int taille;

    taille = my_strlen(str);
    if (taille == size) {
        return 0;
    }
    return 1;
}
