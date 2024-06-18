/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** Return 1 if alphabetical if not 0
*/

#include <stdlib.h>

int my_str_isalpha(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < 'a' || str[i] > 'z'))
            return (0);
    }
    return (1);
}
