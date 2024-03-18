/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** cell_selection.c
*/

#include "../include/amazed.h"

cell_t *select_cell_to_go(cell_t *actual_cell)
{
    cell_t *chosen_cell = actual_cell;

    for (int i = 0; actual_cell->tunnels[i]; i++) {
        if (can_go_to_cell(actual_cell->tunnels[i]) && (chosen_cell == NULL ||
            chosen_cell->move_to_end > actual_cell->tunnels[i]->move_to_end))
            chosen_cell = actual_cell->tunnels[i];
    }
    if (actual_cell == chosen_cell)
        return NULL;
    return chosen_cell;
}
