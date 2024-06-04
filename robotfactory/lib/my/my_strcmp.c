/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** compare 2 string, 0 if they are equal, -1 if the first is lower
** and +1 if it's greater
*/

int my_strcmp(char const *s1, char const *s2)
{
    int counter = 0;

    while (s1[counter] != '\0' && s2[counter] != '\0') {
        if (s1[counter] < s2[counter]) {
            return -1;
        }
        if (s1[counter] > s2[counter]) {
            return 1;
        }
        ++counter;
    }
    if (s1[counter] < s2[counter]) {
        return -1;
    }
    if (s1[counter] > s2[counter]) {
        return 1;
    }
    return 0;
}
