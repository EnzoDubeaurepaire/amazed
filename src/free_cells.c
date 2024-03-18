/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** free_cells.c
*/

#include "../include/amazed.h"

void free_robots_info(robots_info_t *robots_info)
{
    free(robots_info->moved_robots);
    free(robots_info);
}

void free_cells(cell_t **cells)
{
    for (int i = 0; cells[i]; i++) {
        free(cells[i]->robots);
        free(cells[i]->tunnels);
        free(cells[i]);
    }
    free(cells);
}
