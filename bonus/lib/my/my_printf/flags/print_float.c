/*
** EPITECH PROJECT, 2023
** print_float
** File description:
** like flags file but specificly for f specifier
*/
#include "../include/my_printf.h"
#include "../../my.h"

void check_flags_float(long double nb, int *compt, int *list_flagscompt)
{
    if (list_flagscompt[4] > 0 && nb >= 0) {
        my_putchar('+');
        *compt += 1;
    } else if (list_flagscompt[3] > 0 && nb >= 0) {
        my_putchar(' ');
        *compt += 1;
    }
}

static void print_width(int *compt, int *list_flagscompt, long double nb,
    int char_print)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';

    if (list_flagscompt[4] > 0 && nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && nb >= 0)
        char_print++;
    if (width < my_intlen(nb) + char_print + 1)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print + 1); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

static void print_width_int(int *compt, int *list_flagscompt, long nb,
    int char_print)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';

    if (list_flagscompt[4] > 0 && nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && nb >= 0)
        char_print++;
    if (width < my_intlen(nb) + char_print)
        return;
    for (int i = 0; i < width - (my_intlen(nb) + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

static int if_int(int *compt, int *list_flagscompt, long double nb)
{
    nb = nb > 0 ? nb + 0.5 : nb - 0.5;
    print_width_int(compt, list_flagscompt, nb, 0);
    check_flags_float(nb, compt, list_flagscompt);
    my_print_nbr((int)nb);
    if (list_flagscompt[0] > 0 && list_flagscompt[5] == 0) {
        my_putchar('.');
        *compt += 1;
    }
    *compt += my_intlen(nb);
    return 1;
}

int print_float(va_list list, int *compt, int *list_flagscompt)
{
    long double nb;
    int precision = 6;
    int char_print = precision;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] == 0) {
        return if_int(compt, list_flagscompt, nb);
    } else if (list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    char_print = precision;
    if (list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += my_put_float(nb, precision);
    if (list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, nb, char_print);
    return 1;
}
