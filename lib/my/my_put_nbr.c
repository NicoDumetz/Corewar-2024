/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** display any number given as parameter
*/
#include "my.h"
#include <unistd.h>

static void is_null(int n)
{
    if (n == 0){
        my_putchar(n + '0');
    }
}

static void working_part(int nb)
{
    int congruence = 1;
    int printable;

    while ((nb % congruence) < nb){
        congruence = congruence * 10;
    }
    while (nb > 0 || congruence > 1){
        congruence = congruence / 10;
        printable = (nb - (nb % congruence)) / congruence;
        nb = nb - (printable * congruence);
        my_putchar(printable + '0');
    }
}

static void specific_procedure(void)
{
    working_part(21474);
    working_part(83648);
}

static void overflow_procedure(int nb)
{
    int nb1;
    int nb2;

    nb2 = nb % 1000000;
    nb1 = (nb - nb2) / 1000000;
    working_part(nb1);
    if (nb2 == 0){
        for (int i = 0; i < 6; ++i){
            my_putchar('0');
        }
    } else {
        working_part(nb2);
    }
}

int my_put_nbr(int nb)
{
    is_null(nb);
    if (nb == -2147483648){
        my_putchar('-');
        specific_procedure();
        return (0);
    }
    if (nb < 0 && nb){
        nb = -nb;
        my_putchar('-');
    }
    if (nb > 1000000){
        overflow_procedure(nb);
        return (0);
    }
    working_part(nb);
    return (0);
}
