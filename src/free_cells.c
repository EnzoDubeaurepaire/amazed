/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** free_cells.c
*/

/*!
 * @file free_cells.c
*/

#include "../include/amazed.h"

/*!
 *
 * @param robots_info
*/
void free_robots_info(robots_info_t *robots_info)
{
    free(robots_info->moved_robots);
    free(robots_info);
}

/*!
 *
 * @param cells
*/
void free_cells(cell_t **cells)
{
    for (int i = 0; cells[i]; i++) {
        free(cells[i]->robots);
        free(cells[i]->tunnels);
        free(cells[i]);
    }
    free(cells);
}
