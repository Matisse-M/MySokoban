/*
** EPITECH PROJECT, 2023
** main
** File description:
** Main function
*/

#include <stdlib.h>
#include "sokoban.h"

static void player_base_position(soko_t *soko, int i)
{
    for (int j = 0; soko->map[i][j] != '\0'; j++) {
        if (soko->map[i][j] == 'P') {
            soko->player.x = i;
            soko->player.y = j;
        }
    }
}

static int base_position(soko_t *soko, int i, int k)
{
    for (int j = 0; soko->map[i][j] != '\0'; j++) {
        if (soko->map[i][j] == 'O') {
            soko->base[k].x = i;
            soko->base[k].y = j;
            k++;
        }
    }
    return (k);
}

int box_position(soko_t *soko, int i, int kk)
{
    for (int j = 0; soko->map[i][j] != '\0'; j++) {
        if (soko->map[i][j] == 'X') {
            soko->box[kk].x = i;
            soko->box[kk].y = j;
            kk++;
        }
    }
    return (kk);
}

void stock_box(soko_t *soko)
{
    int k = 0;
    int kk = 0;

    for (int i = 0; soko->map[i] != NULL; i++) {
        player_base_position(soko, i);
        k = base_position(soko, i, k);
        kk = box_position(soko, i, kk);
    }
}
