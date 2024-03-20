/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** ceil.c
*/

int my_ceil(double nb)
{
    if ((int)nb != nb)
        return (int)nb + 1;
    return (int)nb;
}

int my_floor(double nb)
{
    return (int)nb;
}
