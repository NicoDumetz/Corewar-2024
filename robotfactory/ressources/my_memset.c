/*
** EPITECH PROJECT, 2024
** my memset
** File description:
** memset
*/
#include "../include/asm.h"
#include "../include/my.h"
#include "../include/op.h"

char *my_memset(char *str, int size)
{
    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return str;
}
