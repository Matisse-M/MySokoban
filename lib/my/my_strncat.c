/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** Contatenates n char between 2 strings
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i < my_strlen(src) && i < nb; i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + my_strlen(src)] = '\0';
    return (dest);
}
