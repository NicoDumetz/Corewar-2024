/*
** EPITECH PROJECT, 2023
** my_str_to_array
** File description:
** convert an srt into multiple word with desired separator
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int count_words(char const *str, char const *separator,
    int len_separator)
{
    int nb_word = 0;
    int out_word = 1;
    int addition = 1;

    for (int i = 0; str[i]; i += addition) {
        if (my_strncmp(str + i, separator, len_separator) == 0) {
            addition = len_separator;
            out_word = 1;
        } else {
            nb_word = (out_word) ? (nb_word + 1) : nb_word;
            out_word = 0;
            addition = 1;
        }
    }
    return nb_word;
}

static char *catch_word(char const *str, char const *separator,
    int len_separator, int *i)
{
    int word_size = 0;
    char *word;

    for (; my_strncmp(str + (word_size + *i), separator, len_separator) != 0 &&
    str[word_size + *i] != '\0'; word_size++);
    word = malloc(word_size + 1);
    for (int j = 0; j < word_size; j++)
        word[j] = str[j + *i];
    word[word_size] = '\0';
    *i += word_size - 1;
    return word;
}

static void assign_word(char **dest, char const *str, char const *separator,
    int len_separator)
{
    int word_place = 0;

    for (int i = 0; str[i]; i++) {
        if (my_strncmp(str + i, separator, len_separator)) {
            dest[word_place] = catch_word(str, separator, len_separator, &i);
            word_place++;
        }
    }
}

char **my_str_to_array(char const *str, char const *separator)
{
    char **dest;
    int len_separator = my_strlen(separator);
    int nb_words = count_words(str, separator, len_separator);

    dest = malloc(sizeof(char *) * (nb_words + 1));
    assign_word(dest, str, separator, len_separator);
    dest[nb_words] = 0;
    return dest;
}
