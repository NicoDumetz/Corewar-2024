/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** swap content of two integer
*/

void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
