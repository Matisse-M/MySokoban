/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** Compare 2 strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    if (my_strlen(s1) == 0 && my_strlen(s2) > 0)
        return (-1);
    if (my_strlen(s1) > 0 && my_strlen(s2) == 0)
        return (1);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] < s2[i])
            return (-1);
        if (s1[i] > s2[i])
            return (1);
    }
    return (0);
}
