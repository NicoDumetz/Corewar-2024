/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** display a number and return the number of
** characters displayed
*/

#include "my_printf.h"
#include "../../my.h"

static long is_negative(long nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    return nb;
}

long my_print_nbr(long nb)
{
    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    nb = is_negative(nb);
    if (nb <= 9) {
        my_putchar(nb + 48);
    } else {
        my_print_nbr(nb / (long)10);
        my_putchar(nb % (long)10 + (long)48);
    }
    return -nb;
}

long my_putnbr_prec(long nb, int precision)
{
    long new_nb;

    if (nb == -2147483648) {
        write(1, "-2147483648", 11);
        return 0;
    }
    nb = is_negative(nb);
    for (int i = 0; i < precision - my_intlen(nb); i++)
        my_putchar('0');
    new_nb = nb;
    if (new_nb <= 9) {
        my_putchar(new_nb + 48);
    } else {
        my_print_nbr(new_nb / 10);
        my_putchar(new_nb % 10 + 48);
    }
    return -nb;
}
