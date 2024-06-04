/*
** EPITECH PROJECT, 2023
** MY GETNBR
** File description:
** function that return an int from a string
*/
#include "my_printf.h"

static int verify_max(int res, int sign)
{
    res *= sign;
    if (res <= -2147483648 || res >= 2147483647)
        return 0;
    return res;
}

static int varsign(int sign, char const *str, int i)
{
    if ((str[i] == '+' && sign > 0) || (str[i] == '-' && sign < 0)) {
        sign *= 1;
    } else {
        sign *= -1;
    }
    return sign;
}

static int setup(char const *str)
{
    if (str[0] == '-' || str[0] == '+')
        return 0;
    if (str[0] >= 48 && str[0] <= 57)
        return 0;
    return 1;
}

int my_gotnbr(char const *str)
{
    int i = 0;
    int sign = 1;
    long res = 0;

    if (setup(str) == 1)
        return 0;
    while (str[i] == '+' || str[i] == '-') {
        sign = varsign(sign, str, i);
        i++;
    }
    res += str[i] - 48;
    i++;
    while (str[i] >= 48 && str[i] <= 57) {
        res *= 10;
        res += str[i] - 48;
        i++;
        if (res <= -2147483648 || res >= 2147483648)
            return 0;
    }
    return verify_max(res, sign);
}
