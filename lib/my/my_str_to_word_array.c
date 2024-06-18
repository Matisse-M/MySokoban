/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** Turn string into word array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

static int is_alphanum(char c)
{
    if (c < 32)
        return (0);
    return (1);
}

static int j_length(char const *str, int i, int j)
{
    int k = 0;

    while (str[j] != '\0' && k < i) {
        if (is_alphanum(str[j]) == 0 && is_alphanum(str[j + 1]) == 1)
            k++;
        j++;
    }
    return (j);
}

static int count_words(char const *str)
{
    int words = 0;
    int letters = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 1)
            letters++;
        if ((is_alphanum(str[i]) == 0 && is_alphanum(str[i + 1]) == 1 &&
            letters > 0) || (is_alphanum(str[i]) == 1 && str[i + 1] == '\0') ||
            (is_alphanum(str[i]) == 0 && str[i + 1] == '\0' && letters > 0))
            words++;
    }
    return (words);
}

static char *count_letters(char const *str, int i)
{
    char *result = NULL;
    int j = 0;
    int k = 0;

    for (int l = 0; is_alphanum(str[l]) == 0; l++)
        j++;
    j = j_length(str, i, j);
    k = j;
    while (str[k] != '\0') {
        if (is_alphanum(str[k]) == 0) {
            result = malloc(sizeof(char) * (k - j + 1));
            return (result);
        }
        k++;
    }
    result = malloc(sizeof(char) * (k - j + 1));
    return (result);
}

static char *fill_letters(char const *str, int i)
{
    char *result = count_letters(str, i);
    int j = 0;
    int k = 0;

    for (int l = 0; is_alphanum(str[l]) == 0; l++)
        j++;
    j = j_length(str, i, j);
    k = j;
    while (str[k] != '\0') {
        if (is_alphanum(str[k]) == 0) {
            result = my_strncpy(result, &str[j], k - j);
            result[k - j] = '\0';
            return (result);
        }
        k++;
    }
    result = my_strncpy(result, &str[j], k - j);
    result[k - j] = '\0';
    return (result);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0;
    char **dest = malloc(sizeof(char *) * (count_words(str) + 1));

    while (i < count_words(str)) {
        dest[i] = fill_letters(str, i);
        i++;
    }
    dest[i] = NULL;
    return (dest);
}
