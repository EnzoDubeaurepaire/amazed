/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** cell.c
*/

#include "../include/amazed.h"

_Bool cell_is_empty(cell_t *cell)
{
    for (int i = 0; i < cell->robots_nb; i++)
        if (cell->robots[i] == 1)
            return 0;
    return 1;
}

_Bool can_go_to_cell(cell_t *cell)
{
    return cell->state == START || cell->state == END || cell_is_empty(cell);
}
