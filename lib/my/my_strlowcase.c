/*
** EPITECH PROJECT, 2023
** my_strlowcase
** File description:
** put all uppercase in lower case
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
    return str;
}
