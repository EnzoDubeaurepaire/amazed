/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** cells_len.c
*/

#include "../include/amazed.h"

size_t cells_len(cell_t **cells)
{
    int i = 0;

    for (; cells[i]; i++);
    return i;
}
