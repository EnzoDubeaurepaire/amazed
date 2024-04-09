/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** move_robots.c
*/

/*!
 * @file move_robots.c
*/

#include "../include/amazed.h"

/*!
 *
 * @param source
 * @param destination
 * @param robots_info
 * @param robot_id
*/
static void move_robot(cell_t *source, cell_t *destination,
    robots_info_t *robots_info, size_t robot_id)
{
    char *str_nb = my_nb_to_str((long)robot_id + 1);

    write_to_buffer(robots_info, "P\0");
    write_to_buffer(robots_info, str_nb);
    free(str_nb);
    write_to_buffer(robots_info, "-\0");
    write_to_buffer(robots_info, destination->name);
    source->robots[robot_id / 64] ^= 1ul << (robot_id - robot_id / 64);
    destination->robots[robot_id / 64] |= 1ul << (robot_id - robot_id / 64);
    source->robots_present--;
    source->has_robots = 0;
    destination->received = 1;
    destination->has_robots = 1;
    destination->robots_present++;
    if (destination->state == END)
        robots_info->robots_end++;
    robots_info->moved_robots[robot_id / 64] |= 1ul <<
        (robot_id - robot_id / 64);
    source->moved++;
}

/*!
 *
 * @param first_move
 * @param robots_info
*/
static void first_move_write(_Bool *first_move, robots_info_t *robots_info)
{
    if (*first_move == 0)
        write_to_buffer(robots_info, " \0");
    if (*first_move == 1)
        *first_move = 0;
}

/*!
 *
 * @param cells
 * @param robot
 * @return
*/
static cell_t *get_robot_cell(cell_t **cells, size_t robot)
{
    for (int i = 0; cells[i]; i++) {
        if (cells[i]->robots[robot / 64] & 1ul << (robot - robot / 64))
            return cells[i];
    }
    return NULL;
}

/*!
 *
 * @param cell
 * @param robots_info
 * @param robot
 * @param first
*/
void move_robot_in_cell(cell_t *cell, robots_info_t *robots_info,
    size_t robot, _Bool *first)
{
    cell_t *to_go;

    if (robots_info->moved_robots[robot / 64] & 1ul << (robot - robot / 64)
        || cell->state == END || cell->moved == cells_len(cell->tunnels))
        return;
    to_go = select_cell_to_go(cell);
    if (to_go) {
        first_move_write(first, robots_info);
        move_robot(cell, to_go, robots_info, robot);
    }
}

/*!
 *
 * @param cells
 * @param robots_info
 * @param robot
 * @param first
*/
static void move_robot_in_cells(cell_t **cells, robots_info_t *robots_info,
    size_t robot, _Bool *first)
{
    cell_t *cell;

    if (robots_info->moved_robots[robot / 64] & 1ul << (robot - robot / 64))
        return;
    cell = get_robot_cell(cells, robot);
    move_robot_in_cell(cell, robots_info, robot, first);
}

/*!
 *
 * @param cells
 * @return
*/
static _Bool no_moves(cell_t **cells)
{
    for (int i = 0; cells[i]; i++)
        if (cells[i]->robots_present != 0 && cells[i]->moved !=
            cells_len(cells[i]->tunnels) && cells[i]->received == 0)
            return 0;
    return 1;
}

/*!
 *
 * @param cells
 * @param robots_info
*/
void move_robots(cell_t **cells, robots_info_t *robots_info)
{
    _Bool first_move = 1;

    for (int i = 0; i < my_ceil((double)robots_info->robots_nb / 64.0); i++)
        robots_info->moved_robots[i] = 0;
    for (int i = 0; cells[i]; i++) {
        cells[i]->moved = 0;
        cells[i]->received = 0;
    }
    for (size_t i = robots_info->robots_end; (size_t)i <
        robots_info->robots_nb; i++) {
        if (no_moves(cells))
            return;
        move_robot_in_cells(cells, robots_info, i, &first_move);
    }
}
