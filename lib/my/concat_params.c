/*
** EPITECH PROJECT, 2023
** concat_params
** File description:
** Concatenates command line into a single string
*/

#include <stdlib.h>

char *concat_params(int argc, char **argv)
{
    int mem = 0;
    int k = 0;
    char *dest = NULL;

    for (int i = 0; argv[i] != NULL; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++)
            mem++;
    }
    dest = malloc(sizeof(char) * (mem + argc + 1));
    for (int i = 0; argv[i] != NULL; i++) {
        for (int j = 0; argv[i][j] != '\0'; j++) {
            dest[k] = argv[i][j];
            k++;
        }
        dest[k] = '\n';
        k++;
    }
    return (dest);
}
