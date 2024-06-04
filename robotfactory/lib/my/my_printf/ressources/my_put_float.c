/*
** EPITECH PROJECT, 2023
** my_put_float
** File description:
** put a float with the given precision and return the
** number of character written
*/
#include "my_printf.h"
#include "../include/my_macro_abs.h"
#include "../../my.h"

static void is_negative(long double *nb, int *compt)
{
    if (*nb < 0) {
        *nb *= -1;
        my_putchar('-');
        *compt += 1;
    }
}

int my_put_float(long double nb, int precision)
{
    double marge = 0.5;
    int compt = my_intlen(ABS(nb));

    is_negative(&nb, &compt);
    for (int k = 0; k < precision; k++) {
        marge /= 10;
    }
    nb += marge;
    nb += my_print_nbr((long)nb);
    my_putchar('.');
    compt++;
    for (int index = 0; index < precision; index++) {
        nb *= (long double)10;
        nb += my_print_nbr((long)nb);
        compt++;
    }
    return compt;
}
