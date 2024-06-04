/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get the first number in an array
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int i = 0;
    int sign = (str[i] == '-') ? -1 : 1;

    if (str[i] == '-' || str[i] == '+')
        i++;
    for (; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'); i++) {
        nbr *= 10;
        nbr += str[i] - '0';
    }
    return nbr * sign;
}
