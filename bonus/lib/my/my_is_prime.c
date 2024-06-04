/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** tell if a number is prime
*/

int my_is_prime(int nb)
{
    int diviseur = 2;
    long long overflow = nb;

    if (overflow > 2147483647 || overflow < -2147483647 - 1){
        return (0);
    }
    if (nb < 2){
        return (0);
    }
    while (diviseur < nb){
        if ((nb % diviseur) == 0){
            return (0);
        }
        ++diviseur;
    }
    return (1);
}
