/*
** EPITECH PROJECT, 2023
** my_isneg
** File description:
** Display 'N' if negative or 'P' if positive or NULL
*/

#include "my.h"

int my_isneg(int n)
{
    if (n < 0)
        my_putchar('N');
    else
        my_putchar('P');
    return (0);
}
