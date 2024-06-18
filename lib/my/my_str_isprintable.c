/*
** EPITECH PROJECT, 2023
** my_str_isprintable
** File description:
** Return 1 if printable 0 if not
*/

#include <stdlib.h>

int my_str_isprintable(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < ' ' || str[i] > '~')
            return (0);
    }
    return (1);
}
