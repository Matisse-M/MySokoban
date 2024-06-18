/*
** EPITECH PROJECT, 2023
** my_is_prime_sup
** File description:
** Return the smallest prime number after a prime number
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    int result = 0;
    int i = 0;

    if (nb == 1)
        return (2);
    if (my_is_prime(nb) != 0)
        return (nb);
    while (my_is_prime(nb + i) == 0) {
        i++;
    }
    result = nb + i;
    return (result);
}
