/*
** EPITECH PROJECT, 2023
** my_put_sci_nbr
** File description:
** display the given int into the scientific way
*/
#include "my_printf.h"
#include "../include/my_macro_abs.h"
#include "../../my.h"

static double arround_the_world(long double nb)
{
    if (nb < 0)
        return -0.5;
    return 0.5;
}

static int printer(long double nb, int nb_mult, int upper, int precision)
{
    int counter = 1;

    if (precision) {
        counter += my_put_float(nb, precision);
    } else {
        counter += my_printf("%d", (int)(nb + arround_the_world(nb)));
    }
    my_putchar((upper) ? 'E' : 'e');
    if (nb_mult >= 0) {
        my_putchar('+');
    } else {
        my_putchar('-');
        nb_mult = -nb_mult;
    }
    counter++;
    if (nb_mult <= 9)
        counter += my_print_nbr(0) + 1;
    my_print_nbr(nb_mult);
    counter += my_intlen(nb_mult);
    return counter;
}

int my_put_sci_nbr(long double nb, int upper, int precision)
{
    int neg;
    double mult;
    int nb_mult = 0;

    if (nb == 0.0)
        return printer(0, 0, upper, precision);
    neg = (nb < 0.0) ? 1 : 0;
    nb = (nb < 0.0) ? -nb : nb;
    mult = (nb >= 1) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10)) {
        nb = nb * mult;
        nb_mult += (mult > 1) ? -1 : 1;
    }
    nb = (neg) ? -nb : nb;
    return printer(nb, nb_mult, upper, precision);
}
