/*
** EPITECH PROJECT, 2023
** my_tablen
** File description:
** Return length of a 2dArray
*/

#include<stdlib.h>

int my_tablen(char **tab)
{
    int i = 0;

    while (tab[i] != NULL)
        i++;
    return (i);
}
