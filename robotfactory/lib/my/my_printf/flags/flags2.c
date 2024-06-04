/*
** EPITECH PROJECT, 2023
** flags2
** File description:
** hold function called in my_printf.c
** that put all modifier flags... for subfunction
*/
#include "../include/my_printf.h"
#include "../../my.h"

static void print_width(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[13];
    int char_print = 0;
    int zero = ' ';

    if (list_flagscompt[0] > 0) {
        char_print += 2;
    }
    for (int i = 0; i < width - (my_strlen(str) + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
    }
    if (list_flagscompt[0] > 0)
        *compt += 2;
}

static void print_width_o(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[13];
    int char_print = 0;
    int zero = ' ';

    if (list_flagscompt[0] > 0) {
        char_print += 1;
    }
    for (int i = 0; i < width - (my_strlen(str) + char_print); i++) {
        my_putchar(zero);
        *compt += 1;
    }
    if (list_flagscompt[0] > 0)
        *compt += 1;
}

static void print_width_d(int *compt, int *list_flagscompt, char *str)
{
    int width = list_flagscompt[13];
    int zero = ' ';

    for (int i = 0; i < width - my_strlen(str); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

int print_oct(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision = list_flagscompt[5];
    char *str;

    nb = check_int_u(list, list_flagscompt);
    nb = list_flagscompt[6] == 2 ? (unsigned char)nb : nb;
    precision = list_flagscompt[0] > 0 ? precision - 1 : precision;
    str = precision >= 0 ? my_put_convert_base_prec(nb, "01234567",
    precision) : my_put_convert_base(nb, "01234567");
    if (list_flagscompt[2] == 0)
        print_width_o(compt, list_flagscompt, str);
    if (list_flagscompt[0] > 0)
        my_putstr("0");
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        print_width_o(compt, list_flagscompt, str);
    *compt += my_strlen(str);
    if (list_flagscompt[5] >= 0)
        free(str);
    return 1;
}

int print_dec(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    nb = list_flagscompt[6] == 2 ? (unsigned char)nb : nb;
    if (list_flagscompt[5] >= 0) {
        precision = list_flagscompt[5];
        str = my_put_convert_base_prec(nb, "0123456789", precision);
    } else
        str = my_put_convert_base(nb, "0123456789");
    if (list_flagscompt[2] == 0)
        print_width_d(compt, list_flagscompt, str);
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        print_width_d(compt, list_flagscompt, str);
    *compt += my_strlen(str);
    if (list_flagscompt[5] >= 0)
        free(str);
    return 1;
}

int print_hex(va_list list, int *compt, int *list_flagscompt)
{
    long nb;
    int precision = 0;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    nb = list_flagscompt[6] == 2 ? (unsigned char)nb : nb;
    precision = list_flagscompt[5];
    str = precision >= 0 ? my_put_convert_base_prec(nb, "0123456789abcdef",
    precision) : my_put_convert_base(nb, "0123456789abcdef");
    if (list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, str);
    if (list_flagscompt[0] > 0)
        my_putstr("0x");
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, str);
    *compt += my_strlen(str);
    if (list_flagscompt[5] >= 0)
        free(str);
    return 1;
}

int print_hex_maj(va_list list, int *compt, int *list_flagscompt)
{
    int nb;
    int precision;
    char *str;

    nb = check_int_u(list, list_flagscompt);
    nb = list_flagscompt[6] == 2 ? (unsigned char)nb : nb;
    precision = list_flagscompt[5];
    str = precision >= 0 ? my_put_convert_base_prec(nb, "0123456789ABCDEF",
    precision) : my_put_convert_base(nb, "0123456789ABCDEF");
    if (list_flagscompt[2] == 0)
        print_width(compt, list_flagscompt, str);
    if (list_flagscompt[0] > 0)
        my_putstr("0X");
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        print_width(compt, list_flagscompt, str);
    *compt += my_strlen(str);
    if (list_flagscompt[5] >= 0)
        free(str);
    return 1;
}
