/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** Turn a char* into a int
*/

static int square(int n, int p)
{
    int v = n;

    if (p == 0)
        return (1);
    for (int i = 0; i < p - 1; i++)
        n *= v;
    return (n);
}

static long to_number(char const *str, int i)
{
    long nb = 0;

    for (int j = 0; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'); i++) {
        if (str[i] > '0')
            j++;
        if (j > 10)
            return (0);
    }
    i--;
    for (int j = 0; i >= 0 && (str[i] >= '0' && str[i] <= '9'); j++) {
        nb += (str[i] - 48) * square(10, j);
        i--;
    }
    return (nb);
}

static long negative(char const *str, long nb, int i)
{
    while ((str[i] == '-' || str[i] == '+') && i > 0) {
        if (str[i] == '-')
            nb *= -1;
        if (str[i] == '+')
            nb *= 1;
        i--;
    }
    return (nb);
}

int my_getnbr(char const *str)
{
    long i = 0;
    long nb = 0;

    while (str[i] < '1' || str[i] > '9') {
        if (str[i] == '\0')
            return (0);
        i++;
    }
    nb = to_number(str, i);
    nb = negative(str, nb, i);
    if (nb < -2147483648 || nb > 2147483647)
        return (0);
    return (nb);
}
