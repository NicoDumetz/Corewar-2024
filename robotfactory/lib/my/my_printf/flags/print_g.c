/*
** EPITECH PROJECT, 2023
** printg
** File description:
** printg %g and %G modifier flags and more
*/

#include "../include/my_printf.h"
#include "../include/my_macro_abs.h"
#include "../../my.h"

static int add_len_decimal(char *str, int counter)
{
    if (str[1]) {
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
    nb = (nb < 0.0) ? -nb : nb;
    counter += my_intlen(nb);
    nb -= (int)nb;
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

static void e_print(int *compt, int *list_flagscompt, long double *nb,
    int precision)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';
    int char_print = precision;

    char_print += *nb < 0 ? 1 : 0;
    if (zero == '0' && *nb < 0) {
        my_putchar('-');
        *nb *= -1;
    }
    if (list_flagscompt[4] > 0 && *nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && *nb >= 0)
        char_print++;
    if (width < science_precision(*nb, precision) + 6)
        return;
    for (int i = 0; i < width - (science_precision(*nb, precision) + 6); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

static void float_print(int *compt, int *list_flagscompt, long double nb,
    int precision)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';
    double marge = 0.5;
    double merge = 0.5;
    int char_print = 0;

    if (list_flagscompt[4] > 0 && nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && nb >= 0)
        char_print++;
    if (width <= float_type(nb,
        precision - get_expos(ABS(nb)) - 1, &marge) + char_print)
        return;
    for (int i = 0; i < width - (float_type(nb,
        precision - get_expos(ABS(nb)) - 1, &merge) + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
        merge = 0.5;
    }
    return;
}

static void print_width(int *compt, int *list_flagscompt, long double nb,
    int precision)
{
    int exp;

    exp = get_expos(ABS(nb));
    if (exp < -4 || exp >= precision) {
        e_print(compt, list_flagscompt, &nb, precision);
        return;
    } else {
        float_print(compt, list_flagscompt, nb, precision);
        return;
    }
}

int print_g(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    long double nb;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if (list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, nb, precision);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_g(nb, precision, 0);
    if (list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, nb, precision);
    return 1;
}

int print_g_maj(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 6;
    long double nb;
    int char_print = 0;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if (list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_g(nb, precision, 1);
    if (list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, nb, char_print);
    return 1;
}
