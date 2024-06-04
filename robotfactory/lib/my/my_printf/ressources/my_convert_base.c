/*
** EPITECH PROJECT, 2023
** my_convert_base
** File description:
** convert a number given in a given base into
** another given base
*/
#include "my_printf.h"
#include "../../my.h"

static char *my_revstr_convert(char *str)
{
    int index;
    int len = my_strlen(str) - 1;
    char temp;

    for (index = 0; index < len; index++) {
        temp = str[index];
        str[index] = str[len];
        str[len] = temp;
        len--;
    }
    return str;
}

char *my_put_convert_base(unsigned long nb, char *base)
{
    int len = my_strlen(base);
    char res[30000];
    int index;

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return my_revstr_convert(res);
    }
    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    return my_revstr_convert(res);
}

char *my_put_convert_base_ptr(unsigned long long nb, char *base)
{
    int len = my_strlen(base);
    char res[30000];
    int index;

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
        return my_revstr_convert(res);
    }
    for (index = 0; nb > 0; index++) {
        res[index] = base[nb % len];
        nb /= len;
    }
    res[index] = '\0';
    return my_revstr_convert(res);
}

static char *calcul_prec(char *res, int precision)
{
    int i;
    char *prec;

    prec = malloc(sizeof(char) * (precision + my_strlen(res)));
    if (precision > my_strlen(res)) {
        for (i = 0; i < precision - my_strlen(res); i++)
            prec[i] = '0';
        prec[i] = '\0';
    }
    my_revstr_convert(res);
    return my_strcat(prec, res);
}

char *my_put_convert_base_prec(unsigned long nb, char *base, int precision)
{
    int len = my_strlen(base);
    char res[1000];
    int index;

    if (nb == 0) {
        res[0] = '0';
        res[1] = '\0';
    } else {
        for (index = 0; nb > 0; index++) {
            res[index] = base[nb % len];
            nb /= len;
        }
        res[index] = '\0';
    }
    return calcul_prec(res, precision);
}
