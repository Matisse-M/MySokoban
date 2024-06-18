/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** Swap two elements
*/

void my_swap(int *a, int *b)
{
    int z = 0;

    z = *a;
    *a = *b;
    *b = z;
}
