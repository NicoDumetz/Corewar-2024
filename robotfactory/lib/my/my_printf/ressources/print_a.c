/*
** EPITECH PROJECT, 2023
** print_a
** File description:
** convert given mentisa into exp 2
*/

#include "my_printf.h"
#include "../../my.h"

static int float_to_hexa(long double nb, int precision, char *base, int compt)
{
    int exp = 0;

    for (; nb > 2; exp++)
        nb /= 2;
    my_putstr("1.");
    nb -= 1;
    compt += 4;
    for (int i = 0; i < precision - 1; i++) {
        nb *= 16;
        my_putchar(base[(int)nb]);
        nb -= (int)nb;
        compt++;
    }
    nb *= 16;
    nb += 0.5;
    my_putchar(base[(int)nb]);
    my_putchar(base[17]);
    my_putchar('+');
    my_print_nbr(exp);
    return compt + 3 + my_intlen(exp);
}

int point_a(double nb, int precision, char *base)
{
    int compt = 0;

    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
        compt++;
    }
    my_putchar('0');
    my_putchar(base[16]);
    if (nb == 0) {
        my_putstr("0p+0");
        return 6;
    }
    return float_to_hexa(nb, precision, base, compt);
}
