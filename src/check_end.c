/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** check_end.c
*/

#include "../include/amazed.h"

cell_t *get_end_cell(cell_t **cells)
{
    for (int i = 0; cells[i]; i++)
        if (cells[i]->state == END)
            return cells[i];
    return NULL;
}

_Bool is_end(cell_t **cells)
{
    cell_t *end = get_end_cell(cells);

    for (int i = 0; i < end->robots_nb; i++)
        if (end->robots[i] == 0)
            return 0;
    return 1;
}
