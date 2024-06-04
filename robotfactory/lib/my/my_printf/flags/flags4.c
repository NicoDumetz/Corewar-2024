/*
** EPITECH PROJECT, 2023
** flags4
** File description:
** hold function called in my_printf.c
** that put all modifier flags... for subfunction
*/
#include "../include/my_printf.h"
#include "../../my.h"

static void print_width_a(int *compt, int *list_flagscompt, long double nb,
    int precision)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';
    int width_a = 7;
    int char_print = 0;

    if (list_flagscompt[4] > 0 && nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && nb >= 0)
        char_print++;
    if (width < width_a + precision + char_print)
        return;
    for (int i = 0; i < width - (width_a + precision + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

int print_a(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 13;
    long double nb;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if (list_flagscompt[2] == 0)
        print_width_a(compt, list_flagscompt, nb, precision);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_a(nb, precision, "0123456789abcdefxp");
    if (list_flagscompt[2] > 0)
        print_width_a(compt, list_flagscompt, nb, precision);
    return 1;
}

int print_a_maj(va_list list, int *compt, int *list_flagscompt)
{
    int precision = 13;
    long double nb;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] >= 0)
        precision = list_flagscompt[5];
    if (list_flagscompt[2] == 0)
        print_width_a(compt, list_flagscompt, nb, precision);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += point_a(nb, precision, "0123456789ABCDEFXP");
    if (list_flagscompt[2] > 0)
        print_width_a(compt, list_flagscompt, nb, precision);
    return 1;
}

static void print_width_b(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[13];
    int zero = ' ';
    int char_print = 0;

    if (list_flagscompt[0] > 0) {
        char_print += 2;
    }
    if (width < my_strlen(str) + char_print)
        return;
    for (int i = 0; i < width - (my_strlen(str) + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
    }
    if (list_flagscompt[0] > 0)
        *compt += 2;
}

int print_bin(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    nb = list_flagscompt[6] == 2 ? (unsigned char)nb : nb;
    precision = list_flagscompt[5];
    str = list_flagscompt[5] >= 0 ? my_put_convert_base_prec(nb, "01"
    , precision) : my_put_convert_base(nb, "01");
    if (list_flagscompt[2] == 0)
        print_width_b(compt, list_flagscompt, str);
    if (list_flagscompt[0] > 0)
        my_putstr("0b");
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        print_width_b(compt, list_flagscompt, str);
    *compt += my_strlen(str);
    if (list_flagscompt[5] >= 0)
        free(str);
    return 1;
}
