/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** return 1 if str is made of only printable char
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] < 32) {
            return 0;
        }
    }
    return 1;
}
