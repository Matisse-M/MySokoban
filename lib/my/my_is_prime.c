/*
** EPITECH PROJECT, 2023
** my_is_prime
** File description:
** Return 1 if prime 0 if not
*/

int my_is_prime(int nb)
{
    if (nb <= 0 || nb == 1)
        return (0);
    for (int i = 1; i < nb; i++) {
        if (nb % i == 0 && i > 1)
            return (0);
    }
    return (1);
}
