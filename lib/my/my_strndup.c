/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Duplicate a string
*/

#include <stdlib.h>
#include "my.h"

char *my_strndup(char const *src, int n)
{
    int i = 0;
    char *dest = malloc(sizeof(char) * (n + 1));

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
