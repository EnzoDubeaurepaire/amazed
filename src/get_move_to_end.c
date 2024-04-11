/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** get_move_to_end.c
*/

/*!
 * @file get_move_end.c
*/

#include "../include/amazed.h"

/*!
 * get the depth of the cell to reach the end cell
 * @param cell: address of the end cell
 * @param depth: depth of the actual cell until the end cell
*/
void rec_get_move_to_end(cell_t *cell, int depth)
{
    cell->move_to_end = depth;
    depth++;
    for (int i = 0; cell->tunnels[i]; i++)
        if (cell->tunnels[i]->move_to_end == -1 ||
            cell->tunnels[i]->move_to_end > depth)
            rec_get_move_to_end(cell->tunnels[i], depth);
}

/*!
 * get all the move until the end for all the cell
 * @param cells: table of cell structure
*/
void get_move_to_end(cell_t **cells)
{
    cell_t *end_cell = get_end_cell(cells);
    int depth = 0;

    rec_get_move_to_end(end_cell, depth);
}
