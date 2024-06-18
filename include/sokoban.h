/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** Sokoban header
*/

#pragma once

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct box_s {
    int x;
    int y;
} box_t;

typedef struct base_s {
    int x;
    int y;
} base_t;

typedef struct soko_s {
    int status;
    int pos_x;
    int pos_y;
    int nb_box;
    int move;
    char **map;
    player_t player;
    box_t *box;
    base_t *base;
} soko_t;


void move_left_right(soko_t *soko, int space);
int ending_condition(soko_t *soko);
void stock_box(soko_t *soko);
