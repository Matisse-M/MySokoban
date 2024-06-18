/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** sort a int array in ascending order
*/

#include <stdio.h>
#include "my.h"

static int lower_cond(int *array, int low, int j)
{
    if (array[j] < low)
        low = array[j];
    return (low);
}

static int stock_cond(int *array, int low, int stock, int j)
{
    if (array[j] < low)
        stock = j;
    return (stock);
}

void my_sort_int_array(int *array, int size)
{
    int low = array[0];
    int stock = 0;

    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            stock = stock_cond(array, low, stock, j);
            low = lower_cond(array, low, j);
        }
        if (array[i] > low) {
            my_swap(&array[i], &array[stock]);
            low = array[i + 1];
        } else {
            low = array[i + 1];
        }
    }
}
