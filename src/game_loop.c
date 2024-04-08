/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** game_loop.c
*/

#include "../include/amazed.h"

static cell_t *get_start_cell(cell_t **cells)
{
    for (int i = 0; cells[i]; i++) {
        if (cells[i]->state == START)
            return cells[i];
    }
    return NULL;
}

void game_loop(cell_t **cells, robots_info_t *robots_info)
{
    get_move_to_end(cells);
    robots_info->robots_end = 0;
    if (get_start_cell(cells)->move_to_end == -1)
        return;
    while (1) {
        move_robots(cells, robots_info);
        write(1, "\n", 1);
        if (is_end(cells))
            return;
    }
}
