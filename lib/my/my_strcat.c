/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** Concatenates 2 strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);

    for (int i = 0; i < my_strlen(src); i++)
        dest[len_dest + i] = src[i];
    dest[len_dest + my_strlen(src)] = '\0';
    return (dest);
}
