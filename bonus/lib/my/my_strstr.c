/*
** EPITECH PROJECT, 2023
** my_strstr
** File description:
** find the first occurence of a string in a string
** and return a pointer to the first letter
*/

#include <stdlib.h>

static int check_eq(char *str, char const *to_find, int i)
{
    int counter = 0;

    while (str[i + counter] == to_find[counter]) {
        ++counter;
        if (to_find[counter] == '\0') {
            return 1;
        }
    }
    return 0;
}

char *my_strstr(char *str, char const *to_find)
{
    if (to_find[0] == '\0') {
        return str;
    }
    for (int i = 0; str[i] != '\0'; ++i) {
        if (check_eq(str, to_find, i)) {
            return (str + i);
        }
    }
    return NULL;
}
