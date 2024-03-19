/*
** EPITECH PROJECT, 2023
** init_cell_struct.c
** File description:
** will init the cell struct
*/

#include "../include/amazed.h"

static int init_bool(cell_t *cell, size_t nb_robots, u_char state)
{
    cell->robots = malloc(sizeof(_Bool) * nb_robots);
    if (cell->robots == NULL)
        return 84;
    if (state == START)
        for (int i = 0; (size_t)i < nb_robots; ++i)
            cell->robots[i] = 1;
    else
        for (int i = 0; (size_t)i < nb_robots; ++i)
            cell->robots[i] = 0;
    return 0;
}

cell_t *init_cell(u_char state, char *name, size_t nb_robots)
{
    cell_t *cell = malloc(sizeof(cell));

    if (cell == NULL)
        return NULL;
    cell->move_to_end = -1;
    cell->moved = 0;
    cell->state = state;
    if (my_strlen(name) > MAX_NAME_LENGTH)
        return NULL;
    my_strcpy(cell->name, name);
    if (init_bool(cell, nb_robots, state) == 84)
        return NULL;
    cell->robots_nb = nb_robots;
    return cell;
}
