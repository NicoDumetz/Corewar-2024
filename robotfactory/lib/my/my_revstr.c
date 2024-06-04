/*
** EPITECH PROJECT, 2023
** my_revstr
** File description:
** reverse a string
*/
#include "my.h"

static void swap(char *a, char *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

char *my_revstr(char *str)
{
    char *start = str;
    char *end = 0;

    if (my_strlen(str) == 0) {
        return (str);
    }
    end = str + my_strlen(str) - 1;
    while (start < end){
        swap(start, end);
        ++start;
        --end;
    }
    return (str);
}
