/*
** EPITECH PROJECT, 2023
** my_compute_square_root
** File description:
** return square root of a number if it's a whole one
*/

int my_compute_square_root(int nb)
{
    int i = 0;

    if (nb > 2147483647 || nb < -2147483647){
        return (0);
    }
    while ((i * i) < nb){
        ++i;
    }
    if ((i * i) > nb){
        return (0);
    }
    return (i);
}
