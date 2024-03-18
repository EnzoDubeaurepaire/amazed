/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** game_loop.c
*/

#include "../include/amazed.h"

void game_loop(cell_t **cells, robots_info_t *robots_info)
{
    get_move_to_end(cells);
    while (1) {
        move_robots(cells, robots_info);
        write(1, "\n", 1);
        if (is_end(cells))
            return;
    }
}
