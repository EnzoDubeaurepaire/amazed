/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** cell_selection.c
*/

#include "../include/amazed.h"

cell_t *select_cell_to_go(cell_t *actual_cell, robots_info_t *robots_infos)
{
    cell_t *chosen_cell = actual_cell;
    int cell_is_okay;

    for (int i = 0; actual_cell->tunnels[i]; i++) {
        cell_is_okay = can_go_to_cell(actual_cell->tunnels[i]);
        if (cell_is_okay != -1 && robots_infos->moved_robots[cell_is_okay] ==
            0 && chosen_cell->move_to_end >
            actual_cell->tunnels[i]->move_to_end) {
            move_robot_in_cell(actual_cell->tunnels[i], robots_infos,
                cell_is_okay);
            cell_is_okay = can_go_to_cell(actual_cell->tunnels[i]);
        }
        if (cell_is_okay == -1 && chosen_cell->move_to_end >
            actual_cell->tunnels[i]->move_to_end)
            chosen_cell = actual_cell->tunnels[i];
    }
    if (actual_cell == chosen_cell)
        return NULL;
    return chosen_cell;
}
