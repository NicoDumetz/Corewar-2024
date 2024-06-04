/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** Copy of printf, this file call each subfunction
** according to the needs
*/
#include "include/my_printf.h"
#include "../my.h"

static int print_suite(const char *format, va_list list, int *compt,
    int *list_flagscompt)
{
    int i = 0;

    for (int p = 0; list_modi[p]; p++) {
        if (list_modi[p] == format[i]) {
            list_flagscompt[6 + p] += 1;
            i += 1;
            p = -1;
        }
    }
    for (int j = 0; fonc_list[j].c; j++) {
        if (format[i] == fonc_list[j].c) {
            fonc_list[j].f(list, compt, list_flagscompt);
            return i;
        }
    }
    write(1, "%", 1);
    *compt += 1;
    return -1;
}

static void get_width(const char *format, va_list list, int *i,
    int *list_flagscompt)
{
    if (format[*i] == '*') {
        list_flagscompt[13] = va_arg(list, int);
        *i += 1;
    } else {
        list_flagscompt[13] = my_gotnbr(format + *i);
        if (list_flagscompt[13] != 0)
            *i += my_intlen(list_flagscompt[13]);
    }
}

static int value(int nb, int i)
{
    if (nb < 0)
        return 0;
    return nb + i;
}

static int print(const char *format, va_list list, int *compt, int i)
{
    int list_flagscompt[] = { 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int j = 0; list_flags[j]; j++) {
        if (format[i] == list_flags[j]) {
            list_flagscompt[j] += 1;
            i += 1;
            j = 0;
        }
    }
    get_width(format, list, &i, list_flagscompt);
    if (format[i] == '.') {
        i += 1;
        list_flagscompt[5] = my_gotnbr(format + i);
        if (list_flagscompt[5] != 0)
            i += my_intlen(list_flagscompt[5]);
        if (format[i] == '0')
            i += 1;
    }
    return value(print_suite((format + i), list, compt, list_flagscompt), i);
}

int my_printf(const char *format, ...)
{
    va_list list;
    int compt = 0;
    int i;

    if (error_handling(format) || fatal_error_handling(format))
        return -1;
    va_start(list, format);
    for (i = 0; i < my_strlen(format); i++) {
        if (format[i] == '%') {
            i += print(format + i, list, &compt, 1);
        } else
            compt += write(1, format + i, 1);
    }
    va_end(list);
    return compt;
}
