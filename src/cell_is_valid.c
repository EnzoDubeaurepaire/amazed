/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** cell.c
*/

/*!
 * @file cell_is_valid.c
*/

#include "../include/amazed.h"

/*!
 * check if the cell contains robots
 * @param cell: a cell structure
 * @return -1 if empty or the index of the robot in the list
*/
int cell_is_empty(cell_t *cell)
{
    for (int i = 0; (size_t)i < cell->robots_nb; i++)
        if (cell->robots[i] == 1)
            return i;
    return -1;
}

/*!
 * check if the robot can go in the cell
 * @param cell: a cell structure
 * @return 1 if it can or 0 if it can't
*/
int can_go_to_cell(cell_t *cell)
{
    if (cell->state == START || cell->state == END || cell->has_robots == 0)
        return 1;
    return 0;
}
