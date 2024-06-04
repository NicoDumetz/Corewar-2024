/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** count and returnthe number of characters in an array
*/

int my_strlen(char const *str)
{
    int counter = 0;

    while (*str != '\0'){
        ++counter;
        ++str;
    }
    return (counter);
}
