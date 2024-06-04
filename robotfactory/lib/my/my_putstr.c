/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** write a wole string with the first adress
*/
#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
