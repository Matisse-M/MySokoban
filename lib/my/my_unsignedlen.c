/*
** EPITECH PROJECT, 2023
** my_unsignedlen
** File description:
** Return the length of an int
*/

int my_unsignedlen(unsigned int nb)
{
    int i = 0;

    while (nb / 10 > 0) {
        i++;
        nb /= 10;
    }
    i++;
    return (i);
}
