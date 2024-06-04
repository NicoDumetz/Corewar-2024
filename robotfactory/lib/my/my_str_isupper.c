/*
** EPITECH PROJECT, 2023
** my_str_isupper
** File description:
** return 1 if str is only made of uppercase
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (!(str[i] >= 'A' && str[i] <= 'Z')) {
            return 0;
        }
    }
    return 1;
}
