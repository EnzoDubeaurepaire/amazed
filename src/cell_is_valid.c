/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** cell.c
*/

#include "../include/amazed.h"

int cell_is_empty(cell_t *cell)
{
    for (int i = 0; i < cell->robots_nb; i++)
        if (cell->robots[i] == 1)
            return i;
    return -1;
}

int can_go_to_cell(cell_t *cell)
{
    int robot = cell_is_empty(cell);

    if (cell->state == START || cell->state == END || robot == -1)
        return -1;
    return robot;
}
