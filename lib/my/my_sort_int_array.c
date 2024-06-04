/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** sort the first occurence of any int in an array
*/
#include "my.h"

static int *loop(int *array, int size, int i)
{
    int *min;

    min = array + i;
    for (int j = i; j < size -1; ++j){
        if (*min > *(array + j)){
            min = array + j;
        }
    }
    return (min);
}

void my_sort_int_array(int *array, int size)
{
    int *min;

    for (int i = 0; i < size - 1; ++i){
        min = loop(array, size, i);
        my_swap(array + i, min);
    }
}
