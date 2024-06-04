/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** convert an srt into multiple word
*/

#include <stdlib.h>

static int is_alphanumeric(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    if (c >= '0' && c <= '9') {
        return 1;
    }
    return 0;
}

static char *catch_word(char const *str, int *i)
{
    int word_size = 0;
    char *word;

    for (int j = *i; is_alphanumeric(str[j]); ++j) {
        word_size += 1;
    }
    word = malloc(word_size + 1);
    for (int j = 0; j < word_size; ++j) {
        word[j] = str[j + *i];
    }
    word[word_size] = '\0';
    *i = *i + word_size - 1;
    return word;
}

static void assign_word(char **dest, char const *str)
{
    int word_place = 0;

    for (int i = 0; str[i] != '\0'; ++i) {
        if (is_alphanumeric(str[i])) {
            dest[word_place] = catch_word(str, &i);
            ++word_place;
        }
    }
}

char **my_str_to_word_array(char const *str)
{
    int separator = 1;
    int word_nbr = 0;
    char **dest;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanumeric(str[i]) && separator) {
            ++word_nbr;
            separator = 0;
        }
        if (is_alphanumeric(str[i]) == 0 && separator == 0) {
            separator = 1;
        }
    }
    dest = malloc(sizeof(char *) * word_nbr + 1);
    assign_word(dest, str);
    dest[word_nbr] = 0;
    return dest;
}
