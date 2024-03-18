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
    source->moved++;
}

static void first_move_write(_Bool *first_move)
{
    if (*first_move == 0)
        write(1, " ", 1);
    if (*first_move == 1)
        *first_move = 0;
}

static cell_t *get_robot_cell(cell_t **cells, size_t robot)
{
    for (int i = 0; cells[i]; i++)
        if (cells[i]->robots[robot] == 1)
            return cells[i];
    return NULL;
}

void move_robot_in_cell(cell_t *cell, robots_info_t *robots_info,
    size_t robot)
{
    cell_t *to_go;

    if (robots_info->moved_robots[robot] || cell->state == END || cell->moved
        == cells_len(cell->tunnels))
        return;
    to_go = select_cell_to_go(cell, robots_info);
    if (to_go)
        move_robot(cell, to_go, robots_info, robot);
}

static void move_robot_in_cells(cell_t **cells, robots_info_t *robots_info,
    size_t robot)
{
    cell_t *cell = get_robot_cell(cells, robot);

    if (robots_info->moved_robots[robot])
        return;
    move_robot_in_cell(cell, robots_info, robot);
}

void move_robots(cell_t **cells, robots_info_t *robots_info)
{
    _Bool first_move = 1;
    _Bool change = 0;

    for (int i = 0; i < robots_info->robots_nb; i++)
        robots_info->moved_robots[i] = 0;
    for (int i = 0; cells[i]; i++)
        cells[i]->moved = 0;
    for (int i = 0; i < robots_info->robots_nb; i++) {
        move_robot_in_cells(cells, robots_info, i);
    }
}
