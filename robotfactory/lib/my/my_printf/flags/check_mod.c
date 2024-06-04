/*
** EPITECH PROJECT, 2023
** check_mod
** File description:
** this file contain function that we gonna use
** to cast variables on length modifier
*/

#include "../include/my_printf.h"

long check_int(va_list list, int *list_flagscompt)
{
    if (list_flagscompt[6] == 1)
        return (short)va_arg(list, int);
    if (list_flagscompt[6] == 2)
        return va_arg(list, int);
    if (list_flagscompt[7] == 1 || list_flagscompt[7] == 2)
        return va_arg(list, long);
    if (list_flagscompt[8] == 1)
        return va_arg(list, intmax_t);
    if (list_flagscompt[9] == 1)
        return va_arg(list, size_t);
    if (list_flagscompt[10] == 1)
        return va_arg(list, ptrdiff_t);
    if (list_flagscompt[12] == 1)
        return va_arg(list, long);
    return va_arg(list, int);
}

unsigned long check_int_u(va_list list, int *list_flagscompt)
{
    if (list_flagscompt[6] == 1)
        return (unsigned short)va_arg(list, unsigned int);
    if (list_flagscompt[6] == 2)
        return va_arg(list, unsigned int);
    if (list_flagscompt[7] == 1 || list_flagscompt[7] == 2)
        return va_arg(list, unsigned long);
    if (list_flagscompt[8] == 1)
        return va_arg(list, uintmax_t);
    if (list_flagscompt[9] == 1)
        return va_arg(list, size_t);
    if (list_flagscompt[10] == 1)
        return va_arg(list, ptrdiff_t);
    if (list_flagscompt[12] == 1)
        return va_arg(list, unsigned long);
    return va_arg(list, unsigned int);
}

long double check_float(va_list list, int *list_flagscompt)
{
    if (list_flagscompt[11] == 1)
        return va_arg(list, long double);
    return va_arg(list, double);
}
