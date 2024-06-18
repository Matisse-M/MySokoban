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

static void menu_h(int ac, char **av)
{
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0) {
            my_putstr("USAGE\n     ./my_sokoban map\n\nDESCRIPTION\n");
            my_putstr("     map  file representing the warehouse map, ");
            my_putstr("containing '#' for walls,\n          'P' for the p");
            my_putstr("layer, 'X' for boxes and 'O' for storage locations.\n");
            exit(0);
        }
    }
}

static void map_is_okay(char *buffer)
{
    int x = 0;
    int o = 0;
    int p = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X')
            x++;
        if (buffer[i] == 'O')
            o++;
        if (buffer[i] == 'P')
            p++;
        if (buffer[i] != ' ' && buffer[i] != 'P' && buffer[i] != 'O' &&
            buffer[i] != 'X' && buffer[i] != '#' && buffer[i] != '\n')
            exit(84);
    }
    if (p < 1 || p > 1)
        exit(84);
    if (x != o)
        exit(84);
}

static int find_longer_line(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        if (len < my_strlen(tab[i]))
            len = my_strlen(tab[i]);
    }
    return (len);
}

static int nb_base(char *buffer)
{
    int nb = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == 'X')
            nb++;
    }
    return (nb);
}

static soko_t fill_sokoban(char const *str)
{
    soko_t soko;
    int fd = open(str, O_RDONLY);
    char *buffer = NULL;

    if (fd == -1)
        exit(84);
    buffer = malloc(sizeof(char) * (32000));
    read(fd, buffer, 32000);
    buffer[31999] = '\0';
    map_is_okay(buffer);
    soko.nb_box = nb_base(buffer);
    soko.map = my_str_to_word_array(buffer);
    soko.box = malloc(sizeof(base_t) * soko.nb_box);
    soko.base = malloc(sizeof(base_t) * soko.nb_box);
    soko.move = 0;
    stock_box(&soko);
    free(buffer);
    return (soko);
}

static void display_map(soko_t *soko)
{
    move(5, COLS / 2 - 25);
    printw("|\\  /| \\   /    ---- ____ |   / ____  ___   /\\  |\\  |\n");
    move(6, COLS / 2 - 25);
    printw("| \\/ |  \\ /    |___ |    ||--| |    ||___) /__\\ | \\ |\n");
    move(7, COLS / 2 - 25);
    printw("|    |   |     ____| ---- |   \\ ---- |___)/    \\|  \\|\n");
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    for (int i = 0; soko->map[i] != NULL; i++) {
        move(LINES / 2 - my_tablen(soko->map) / 2 + i, COLS / 2 -
            find_longer_line(soko->map) / 2);
        printw("%s\n", soko->map[i]);
    }
    for (int i = 0; i < soko->nb_box; i++) {
        if (soko->map[soko->base[i].x][soko->base[i].y] != 'X' &&
            soko->map[soko->base[i].x][soko->base[i].y] != 'P')
            soko->map[soko->base[i].x][soko->base[i].y] = 'O';
    }
    attron(COLOR_PAIR(1));
    printw("\n\n\n\n\n          [Movements: %d]\n", soko->move);
    attroff(COLOR_PAIR(1));
}

static void my_sokoban(soko_t *soko, char *map)
{
    int space = 0;
    int i = 1;

    while (i == 1) {
        display_map(soko);
        space = getch();
        if (space == 32)
            *soko = fill_sokoban(map);
        move_left_right(soko, space);
        i = ending_condition(soko);
        display_map(soko);
        refresh();
        clear();
    }
}

int main(int ac, char **av)
{
    soko_t soko;

    if (ac < 2 || ac > 2)
        exit(84);
    menu_h(ac, av);
    soko = fill_sokoban(av[1]);
    initscr();
    noecho();
    curs_set(0);
    my_sokoban(&soko, av[1]);
    endwin();
    return (soko.status);
}
