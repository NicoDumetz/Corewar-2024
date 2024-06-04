/*
** EPITECH PROJECT, 2023
** my_compute_power_rec
** File description:
** return nb^p using recursivity
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 1){
        if (p < 0){
            return (0);
        }
        return (1);
    }
    if (nb > 2147483647){
        return (0);
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}
