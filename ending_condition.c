/*
** EPITECH PROJECT, 2023
** main
** File description:
** Main function
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

static int win_condition(soko_t *soko)
{
    for (int i = 0; i < soko->nb_box; i++) {
        if (soko->map[soko->base[i].x][soko->base[i].y] != 'X')
            return (1);
    }
    soko->status = 0;
    return (0);
}

static int is_corner(char a, char b, char c, char d)
{
    if ((a == '#' || a == 'X') &&
        (b == '#' || b == 'X'))
        return (1);
    if ((a == '#' || a == 'X') &&
        (c == '#' || c == 'X'))
        return (1);
    if ((d == '#' || d == 'X') &&
        (b == '#' || b == 'X'))
        return (1);
    if ((d == '#' || d == 'X') &&
        (c == '#' || c == 'X'))
        return (1);
    return (0);
}

static int check_stuck(soko_t *soko, int i, int j)
{
    if (soko->map[i][j] == 'X' && is_corner(soko->map[i + 1][j],
        soko->map[i][j + 1], soko->map[i][j - 1], soko->map[i - 1][j]) == 1)
        return (1);
    return (0);
}

static int lose_condition(soko_t *soko)
{
    int stuck = 0;

    for (int i = 0; soko->map[i] != NULL; i++)
        for (int j = 0; soko->map[i][j] != '\0'; j++)
            stuck += check_stuck(soko, i, j);
    if (stuck == soko->nb_box) {
        soko->status = 1;
        return (0);
    }
    return (1);
}

int ending_condition(soko_t *soko)
{
    int i = 1;

    i = win_condition(soko);
    if (i == 0) {
        return (i);
    }
    i = lose_condition(soko);
    return (i);
}
