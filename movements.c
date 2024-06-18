/*
** EPITECH PROJECT, 2023
** movements
** File description:
** Function to handle movements
*/

#include <ncurses.h>
#include "my.h"
#include "sokoban.h"

static int is_free(char c)
{
    if (c == ' ' || c == 'O')
        return (1);
    return (0);
}

static void move_up(soko_t *soko)
{
    if (is_free(soko->map[soko->player.x - 1][soko->player.y]) == 1) {
        soko->map[soko->player.x - 1][soko->player.y] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.x--;
        soko->move++;
    } else if ((soko->map[soko->player.x - 2][soko->player.y] != '#' &&
        soko->map[soko->player.x - 2][soko->player.y] != 'X') &&
        soko->map[soko->player.x - 1][soko->player.y] == 'X') {
        soko->map[soko->player.x - 2][soko->player.y] = 'X';
        soko->map[soko->player.x - 1][soko->player.y] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.x--;
        soko->move++;
    }
}

static void move_down(soko_t *soko)
{
    if (is_free(soko->map[soko->player.x + 1][soko->player.y]) == 1) {
        soko->map[soko->player.x + 1][soko->player.y] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.x++;
        soko->move++;
    } else if ((soko->map[soko->player.x + 2][soko->player.y] != '#' &&
        soko->map[soko->player.x + 2][soko->player.y] != 'X') &&
        soko->map[soko->player.x + 1][soko->player.y] == 'X') {
        soko->map[soko->player.x + 2][soko->player.y] = 'X';
        soko->map[soko->player.x + 1][soko->player.y] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.x++;
        soko->move++;
    }
}

static void move_left(soko_t *soko)
{
    if (is_free(soko->map[soko->player.x][soko->player.y - 1]) == 1) {
        soko->map[soko->player.x][soko->player.y - 1] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.y--;
        soko->move++;
    } else if ((soko->map[soko->player.x][soko->player.y - 2] != '#' &&
        soko->map[soko->player.x][soko->player.y - 2] != 'X') &&
        soko->map[soko->player.x][soko->player.y - 1] == 'X') {
        soko->map[soko->player.x][soko->player.y - 2] = 'X';
        soko->map[soko->player.x][soko->player.y - 1] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.y--;
        soko->move++;
    }
}

static void move_right(soko_t *soko)
{
    if (is_free(soko->map[soko->player.x][soko->player.y + 1]) == 1) {
        soko->map[soko->player.x][soko->player.y + 1] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.y++;
        soko->move++;
    } else if ((soko->map[soko->player.x][soko->player.y + 2] != '#' &&
        soko->map[soko->player.x][soko->player.y + 2] != 'X') &&
        soko->map[soko->player.x][soko->player.y + 1] == 'X') {
        soko->map[soko->player.x][soko->player.y + 2] = 'X';
        soko->map[soko->player.x][soko->player.y + 1] = 'P';
        soko->map[soko->player.x][soko->player.y] = ' ';
        soko->player.y++;
        soko->move++;
    }
}

void move_left_right(soko_t *soko, int space)
{
    if (space == 65 && soko->player.x > 1)
        move_up(soko);
    if (space == 66 && my_tablen(soko->map) - 1 > soko->player.x + 1)
        move_down(soko);
    if (space == 67 && my_strlen(soko->map[soko->player.x]) >
        soko->player.y + 1)
        move_right(soko);
    if (space == 68 && soko->player.y > 1)
        move_left(soko);
}
