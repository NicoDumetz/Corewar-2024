/*
** EPITECH PROJECT, 2023
** my_find_prime_sup
** File description:
** find the first prime number superior or equal
*/

static int prime_search(int nb)
{
    int diviseur = 2;

    if (nb > 2147483647 || nb < -2147483647 - 1){
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

int my_find_prime_sup(int nb)
{
    int i = 0;

    if (nb <= 2){
        return (2);
    }
    while (!(prime_search(nb + i))){
        ++i;
        if ((nb + i) % 2 == 0){
            ++i;
        }
    }
    return (nb + i);
}
