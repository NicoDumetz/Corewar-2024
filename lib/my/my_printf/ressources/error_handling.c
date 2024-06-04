/*
** EPITECH PROJECT, 2023
** error_handling
** File description:
** my_printf function that makes my_printf return -1 in case of problem
** (like printf even if sometimes it make simply no sense)
*/
#include "my_printf.h"

static int modi_test(const char *format, int i, char c)
{
    if (c != 'l' && c != 'h')
        return 1;
    if (format[i + 1] == c)
        return 2;
    return 1;
}

static int error_loop_loop(const char *format, int *i)
{
    for (int j = 0; list_modi[j]; j++) {
        if (format[*i] == list_modi[j])
            *i += modi_test(format, *i, list_modi[j]);
    }
    for (int j = 0; fonc_list[j].c; j++)
        if (fonc_list[j].c == format[*i])
            return 1;
    if (format[*i] == '\0' || format[*i] == 'S')
        return -1;
    return 0;
}

static int fatal_error_loop(const char *format, int *i)
{
    char spe_crash[7] = {'l', 'j', 'z', 't', 'L', 'q', 0};

    for (int j = 0; list_modi[j]; j++) {
        if (format[*i] == list_modi[j])
            *i += modi_test(format, *i, list_modi[j]);
    }
    for (int j = 0; spe_crash[j]; j++) {
        if (format[*i - 1] == spe_crash[j] && format[*i] == 's')
            return 1;
    }
    return 0;
}

static int error_loop(const char *format, int *i, int fatal)
{
    for (int j = 0; list_flags[j]; j++) {
        if (format[*i] == list_flags[j]) {
            ++*i;
            j = 0;
        }
    }
    if (format[*i] >= '0' && format[*i] <= '9')
        *i += my_intlen(my_gotnbr(format + *i));
    else
        if (format[*i] == '*')
            ++*i;
    if (format[*i] == '.') {
        ++*i;
        while (format[*i] >= '0' && format[*i] <= '9')
            ++*i;
    }
    if (fatal)
        return 0;
    return error_loop_loop(format, i);
}

int fatal_error_handling(const char *format)
{
    int result = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            ++i;
            error_loop(format, &i, 1);
            result = fatal_error_loop(format, &i);
        }
        if (result)
            return result;
    }
    return result;
}

int error_handling(const char *format)
{
    int prev = 0;
    int actual = 1;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            ++i;
            prev = actual;
            actual = error_loop(format, &i, 0);
        }
        if (prev == 1 && actual == -1)
            return 1;
    }
    return 0;
}
