/*
** EPITECH PROJECT, 2023
** convert_base
** File description:
** Convert n base into n  other_base
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static long convert_base_ten(char const *nbr, char const *base_from)
{
    int len_base = my_strlen(base_from);
    int j = 0;
    long temp = 0;

    for (int i = 0; nbr[i] != '\0'; i++) {
        for (; nbr[i] != base_from[j]; j++);
        temp += j * my_compute_power_rec(len_base, my_strlen(nbr) - 1 - i);
        j = 0;
    }
    return (temp);
}

static char *convert_base_to_higher(long nb, char const *base_to, int neg)
{
    int len_base = my_strlen(base_to);
    int j = 0;
    int i = 0;
    char *result = malloc(sizeof(char) * (100));

    for (long n = nb; n > 0; n /= len_base) {
        for (; base_to[n % len_base] != base_to[j]; j++);
        result[i] = base_to[j];
        j = 0;
        i++;
        if (neg == 1 && n / 10 == 0)
            result[i] = '-';
    }
    result[i] = '\0';
    return (my_revstr(result));
}

char *convert_base(char const *nbr, char const *base_from, char const *base_to)
{
    long nb = 0;
    int neg = 0;
    char *maj = NULL;

    if (nbr[0] == '0' && my_strlen(nbr) == 1)
        return ("0");
    if (my_strlen(nbr) == 0 || my_strlen(base_from) == 0 ||
        my_strlen(base_to) == 0)
        return (NULL);
    if (nbr[0] == '-')
        neg++;
    maj = my_strdup(&nbr[neg]);
    nb = convert_base_ten(maj, base_from);
    return (convert_base_to_higher(nb, base_to, neg));
}
