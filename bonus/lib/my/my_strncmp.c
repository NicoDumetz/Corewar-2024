/*
** EPITECH PROJECT, 2023
** strncmp
** File description:
** compare two string based on their n first characters
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i++) {
        if (s1[i] < s2[i]) {
            return -1;
        }
        if (s1[i] > s2[i]) {
            return 1;
        }
        if (s1[i] == '\0' && s2[i] == '\0') {
            return 0;
        }
    }
    return 0;
}
