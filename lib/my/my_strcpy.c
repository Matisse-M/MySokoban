/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Copy a string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (i < my_strlen(src)) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
