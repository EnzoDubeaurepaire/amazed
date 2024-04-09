/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

/*!
 * @file check_name_cell.c
*/

#include "../include/amazed.h"

/*!
 * check in the cell list if the name exist
 * @param tab is table of cell struct
 * @param name is the name we check
 * @return l'adresse de la cellule si trouvé snon renvoie NULL
*/
cell_t *check_name_cell(cell_t **tab, char *name)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i]->name, name) == 0) {
            return tab[i];
        }
    }
    return NULL;
}
