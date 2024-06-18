/*
** EPITECH PROJECT, 2023
** my_put_unsigned
** File description:
** Display an unsigned int
*/

#include "my.h"

int my_put_unsigned(unsigned int nb)
{
    unsigned int n = nb;

    if (n / 10 != 0)
        my_put_unsigned(n / 10);
    my_putchar(n % 10 + '0');
    return (0);
}
