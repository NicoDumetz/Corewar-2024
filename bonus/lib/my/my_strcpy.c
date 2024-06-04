/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** copy src string into dest string
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
