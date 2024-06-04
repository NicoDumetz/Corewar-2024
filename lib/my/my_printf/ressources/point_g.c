/*
** EPITECH PROJECT, 2023
** point_g
** File description:
** un abile jeu de mot avec le point g
** this function display an int into float or in float if float
** take less space, while deleting useless 0, this function
** return the number of characters displayed.
*/
#include "my_printf.h"
#include "../include/my_macro_abs.h"
#include "../../my.h"

static int put_nbr(long double nb)
{
    if (nb < 0 && ABS(nb) < 1)
        my_putchar('-');
    return my_print_nbr((int)nb);
}

static int add_len_decimal(char *str, int counter)
{
    if (str[1] >= 48 && str[1] <= 57) {
        my_printf("%s", str);
        counter += my_strlen(str);
    }
    free(str);
    return counter;
}

static int float_type(long double nb, long double precision, double *marge)
{
    char *str;
    int counter = (nb < 0.0) ? 1 : 0;

    for (int k = 0; k < precision; k++)
        *marge /= 10;
    nb += (nb >= 0) ? *marge : -(*marge);
    counter += my_intlen(ABS(nb));
    nb += put_nbr(nb);
    nb = (nb < 0.0) ? -nb : nb;
    str = malloc(precision + 1);
    str[0] = '.';
    for (int k = 0; k < precision; k++) {
        nb *= 10;
        str[k + 1] = ((int)nb % 10) + '0';
        nb = nb - (((int)nb / 10) * 10);
    }
    for (int k = precision; k >= 0 && str[k] == '0'; k--)
        str[k] = '\0';
    return add_len_decimal(str, counter);
}

static int precision_loop(long double nb, int precision)
{
    char *str;

    str = malloc(precision);
    for (int k = 0; k < precision - 1; k++) {
        nb *= 10;
        str[k] = ((int)nb % 10) + '0';
    }
    for (int k = precision - 2; k >= 0; k--) {
        if (str[k] > '0' && str[k] <= '9')
            break;
        precision--;
    }
    free(str);
    return precision - 1;
}

int science_precision(long double nb, double precision)
{
    double mult;
    double marge = 0.5;

    for (int k = 0; k < precision - 1; k++)
        marge /= 10;
    nb = (nb < 0.0) ? -nb : nb;
    mult = (nb >= 1) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10))
        nb *= mult;
    nb += marge;
    return precision_loop(nb, precision);
}

int get_expos(long double nb)
{
    double mult;
    int exp = 0;

    if (nb == 0.0) {
        return exp;
    }
    mult = (nb >= 1.0) ? 0.1 : 10.0;
    while (!(nb >= 1 && nb < 10)) {
        nb *= mult;
        exp += (mult < 1) ? 1 : -1;
    }
    return exp;
}

int point_g(long double nb, int precision, int upper)
{
    double marge = 0.5;
    int exp;

    precision = (precision <= 0) ? 1 : precision;
    exp = get_expos(ABS(nb));
    if (exp < -4 || exp >= precision) {
        return my_put_sci_nbr(nb, upper, science_precision(nb, precision));
    } else {
        return float_type(nb, precision - exp - 1, &marge);
    }
}
