/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** move_robots.c
*/

#include "../include/amazed.h"

static void move_robot(cell_t *source, cell_t *destination,
    robots_info_t *robots_info, size_t robot_id)
{
    write(1, "P", 1);
    my_putnbr((long)robot_id + 1);
    write(1, "-", 1);
    write(1, destination->name, my_strlen(destination->name));
    source->robots[robot_id] = 0;
    destination->robots[robot_id] = 1;
    robots_info->moved_robots[robot_id] = 1;
}

static void first_move_write(_Bool *first_move)
{
    if (*first_move == 0)
        write(1, " ", 1);
    if (*first_move == 1)
        *first_move = 0;
}

static void move_robots_in_cell(cell_t *cell, robots_info_t *robots_info, _Bool *first_move)
{
    cell_t *cell_to_go;

    if (cell->state == END)
        return;
    for (int i = 0; i < cell->robots_nb; i++)
        if (cell->robots[i] == 1 && robots_info->moved_robots[i] == 0 &&
            select_cell_to_go(cell)) {
            cell_to_go = select_cell_to_go(cell);
            first_move_write(first_move);
            move_robot(cell, cell_to_go, robots_info, i);
        }
}

void move_robots(cell_t **cells, robots_info_t *robots_info)
{
    _Bool first_move = 1;

    for (int i = 0; i < robots_info->robots_nb; i++)
        robots_info->moved_robots[i] = 0;
    for (int j = 0; j < robots_info->robots_nb; j++)
        for (int i = 0; cells[i]; i++)
            move_robots_in_cell(cells[i], robots_info, &first_move);
}
