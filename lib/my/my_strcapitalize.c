/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** capitalize a string putting first letter in upcase
** and other in lowercase
*/

static void upcase(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        str[i] = str[i] - 32;
    }
}

static void lowcase(char *str, int i)
{
    if (str[i] >= 'A' && str[i] <= 'Z') {
        str[i] = str[i] + 32;
    }
}

char *my_strcapitalize(char *str)
{
    int up = 1;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (up) {
            upcase(str, i);
            up = 0;
        } else {
            lowcase(str, i);
        }
        if (str[i] == '+' || str[i] == '-' || str[i] == ' ') {
            up = 1;
        }
    }
    return str;
}
