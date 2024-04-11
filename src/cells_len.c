/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** cells_len.c
*/

/*!
 * @file cells_len.c
*/

#include "../include/amazed.h"

/*!
 * get the nbr of cell structure in the linked list
 * @param cells: table of cell_t
 * @return the len
*/
size_t cells_len(cell_t **cells)
{
    int i = 0;

    for (; cells[i]; i++);
    return i;
}
