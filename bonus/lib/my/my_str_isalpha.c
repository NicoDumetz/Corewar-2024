/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** return 1 if a string is alphabetic (or empty)
*/

int my_str_isalpha(char const *str)
{
    char temp;

    for (int i = 0; str[i] != '\0'; ++i) {
        temp = str[i];
        if (!((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}
