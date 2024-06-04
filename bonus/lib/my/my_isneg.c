/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** a program that display N if the integer passed in argument is negative
** and P if it's positif or null.
*/
#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n < 0){
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
