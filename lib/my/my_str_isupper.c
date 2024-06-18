/*
** EPITECH PROJECT, 2023
** my_str_islower
** File description:
** Return 1 if lowcase 0 if not
*/

#include <stdlib.h>

int my_str_isupper(char const *str)
{
    if (str == NULL)
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return (0);
    }
    return (1);
}
