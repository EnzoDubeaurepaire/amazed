/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../include/amazed.h"

cell_t *check_name_cell(cell_t **tab, char *name)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i]->name, name) == 0) {
            return tab[i];
        }
    }
    return NULL;
}
