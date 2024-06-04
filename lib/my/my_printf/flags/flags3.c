/*
** EPITECH PROJECT, 2023
** flags3
** File description:
** hold function called in my_printf.c
** that put all modifier flags... for subfunction
*/
#include "../include/my_printf.h"
#include "../../my.h"

static void print_width_e(int *compt, int *list_flagscompt, long double *nb,
    int char_print)
{
    int width = list_flagscompt[13];
    int zero = list_flagscompt[1] > 0 && list_flagscompt[2] == 0 ? '0' : ' ';

    char_print += *nb < 0 ? 1 : 0;
    if (zero == '0' && *nb < 0) {
        my_putchar('-');
        *nb *= -1;
    }
    if (list_flagscompt[4] > 0 && *nb >= 0) {
        char_print++;
    } else if (list_flagscompt[3] > 0 && *nb >= 0)
        char_print++;
    if (width < char_print + 6)
        return;
    for (int i = 0; i < width - (char_print + 6); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

int print_science_lowercase(va_list list, int *compt, int *list_flagscompt)
{
    long double nb;
    int precision = 6;
    int char_print;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    char_print = precision;
    if (list_flagscompt[2] == 0)
        print_width_e(compt, list_flagscompt, &nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += my_put_sci_nbr(nb, 0, precision);
    if (list_flagscompt[2] > 0)
        print_width_e(compt, list_flagscompt, &nb, char_print);
    return 1;
}

int print_science_uppercase(va_list list, int *compt, int *list_flagscompt)
{
    long double nb;
    int precision = 6;
    int char_print;

    nb = check_float(list, list_flagscompt);
    if (list_flagscompt[5] > 0)
        precision = list_flagscompt[5];
    char_print = precision;
    if (list_flagscompt[2] == 0)
        print_width_e(compt, list_flagscompt, &nb, char_print);
    check_flags_float(nb, compt, list_flagscompt);
    *compt += my_put_sci_nbr(nb, 1, precision);
    if (list_flagscompt[2] > 0)
        print_width_e(compt, list_flagscompt, &nb, char_print);
    return 1;
}

static void width_adresse(int *compt, char *str, int precision,
    int *list_flagscompt)
{
    int width = list_flagscompt[13];
    int zero = ' ';

    if (width < my_strlen(str) + precision + 2)
        return;
    for (int i = 0; i < width - (precision + 2); i++) {
        my_putchar(zero);
        *compt += 1;
    }
}

static void width_adr(int precision, char *str, int *compt)
{
    if (precision > my_strlen(str)) {
        for (int i = 0; i < precision - my_strlen(str); i++) {
            my_putchar('0');
            *compt += 1;
        }
    }
}

int print_adresse(va_list list, int *compt, int *list_flagscompt)
{
    unsigned long long nb;
    char *str;
    int precision = list_flagscompt[5] >= 0 ? list_flagscompt[5] : 0;

    nb = va_arg(list, unsigned long long);
    str = my_put_convert_base_ptr(nb, "0123456789abcdef");
    width_adresse(compt, str, precision, list_flagscompt);
    my_putstr("0x");
    *compt += 2;
    if (list_flagscompt[2] == 0)
        width_adr(precision, str, compt);
    my_putstr(str);
    if (list_flagscompt[2] > 0)
        width_adr(precision, str, compt);
    *compt += my_strlen(str);
    return 1;
}

int print_compt(va_list list, int *compt, int *list_flagscompt)
{
    int *var;

    var = va_arg(list, int *);
    if (list_flagscompt[6] == 2)
        *var = (signed char)*var;
    *var = *compt;
    return 1;
}

/*
static void check_ptr(int *var, int *list_flagscompt)
{
    if (list_flagscompt[6] == 1)
        (short int)*var;
    if (list_flagscompt[6] == 2)
        (int)*var;
    if (list_flagscompt[7] == 1 || list_flagscompt[7] == 2)
        (long)*var;
    if (list_flagscompt[8] == 1)
        (intmax_t)*var;
    if (list_flagscompt[9] == 1)
        (size_t)*var;
    if (list_flagscompt[10] == 1)
        (ptrdiff_t)*var;
    if (list_flagscompt[10] == 1)
        (long)*var;
}

int print_compt(va_list list, int *compt, int *list_flagscompt)
{
    int *var;

    var = va_arg(list, int *);
    check_ptr(var, list_flagscompt);
    if (list_flagscompt[6] == 2)
        *var = (signed char)*var;
    *var = *compt;
    return 1;
}
*/
