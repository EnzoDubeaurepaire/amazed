/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** check_end.c
*/

/*!
 * @file check_end.c
*/

#include "../include/amazed.h"

/*!
 *
 * @param cells
 * @return
*/
cell_t *get_end_cell(cell_t **cells)
{
    for (int i = 0; cells[i]; i++)
        if (cells[i]->state == END)
            return cells[i];
    return NULL;
}

/*!
 *
 * @param cells
 * @return
*/
_Bool is_end(cell_t **cells)
{
    cell_t *end = get_end_cell(cells);

    if (end->robots_present == end->robots_nb)
        return 1;
    return 0;
}
