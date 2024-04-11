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
 * get the address of the end cell
 * @param cells: table of cell
 * @return either the address if exist or NULL if doesn't
*/
cell_t *get_end_cell(cell_t **cells)
{
    for (int i = 0; cells[i]; i++)
        if (cells[i]->state == END)
            return cells[i];
    return NULL;
}

/*!
 * check if the number of robot in the end cell is equal to the number total
 * of number to see if this is the end of the program
 * @param cells: table of cell structure
 * @return either 1 if end or 0 if not
*/
_Bool is_end(cell_t **cells)
{
    cell_t *end = get_end_cell(cells);

    if (end->robots_present == end->robots_nb)
        return 1;
    return 0;
}
