/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** init_cells.c
*/

/*!
 * @file init_cells.c
*/

#include "../include/amazed.h"

/*!
 * count the number of cell there is in the linked list cell_parsing_info_t
 * @param cell_list:linked_list
 * @return the nbr of cell
*/
static size_t count_cells(cell_parsing_info_t *cell_list)
{
    size_t nb = 0;

    for (; cell_list; cell_list = cell_list->next)
        nb++;
    return nb;
}

/*!
 * init the table of cell structure for the algo
 * @param parsing_info: structure which as been fill with all the information
 * during the parsing
 * @return the table of cell struct
*/
cell_t **init_cells(parsing_info_t *parsing_info)
{
    size_t cell_nb = count_cells(parsing_info->cell_list);
    cell_t **cells = malloc(sizeof(cell_t *) * (cell_nb + 1));
    cell_parsing_info_t *cell_list = parsing_info->cell_list;

    cells[cell_nb] = NULL;
    for (int i = 0; (size_t)i < cell_nb; i++) {
        cells[i] = init_cell(1 * cell_list->end + 2 *
            (!cell_list->end && !cell_list->start
            ), cell_list->name, parsing_info->robot_nb);
        cell_list = cell_list->next;
    }
    return cells;
}

/*!
 * count the number of tunnel will be connected to the cell
 * @param name: name of the cell
 * @param tunnels: linked_list of tunnel
 * @return nbr of tunnel
*/
static size_t count_tunnels_in_cell(char *name, tunnel_t *tunnels)
{
    size_t nb = 0;

    for (; tunnels; tunnels = tunnels->next) {
        if (my_strcmp(name, tunnels->name1) == 0 ||
            my_strcmp(name, tunnels->name2) == 0)
            nb++;
    }
    return nb;
}

/*!
 * get the address of the cell thanks to its name
 * @param name: name of the cell
 * @param cells: table of cell structure
 * @return either the address of the cell of NULL of it doesn't exist
*/
static cell_t *get_cell_from_name(char *name, cell_t **cells)
{
    for (int i = 0; cells[i]; i++)
        if (my_strcmp(cells[i]->name, name) == 0)
            return cells[i];
    return NULL;
}

/*!
 * init the table of tunnel one cell of the table
 * @param name: name of the cell
 * @param cells: table of cell structure
 * @param tunnels: linked list of tunnel
 * @return the table of tunnel
*/
static cell_t **get_tunnels(char *name, cell_t **cells, tunnel_t *tunnels)
{
    size_t tunnel_in_cell = count_tunnels_in_cell(name, tunnels);
    cell_t **tunnels_list = malloc(sizeof(cell_t *) * (tunnel_in_cell + 1));
    int i = 0;

    for (; tunnels; tunnels = tunnels->next) {
        if (my_strcmp(name, tunnels->name1) == 0) {
            tunnels_list[i] = get_cell_from_name(tunnels->name2, cells);
            i++;
            continue;
        }
        if (my_strcmp(name, tunnels->name2) == 0) {
            tunnels_list[i] = get_cell_from_name(tunnels->name1, cells);
            i++;
        }
    }
    tunnels_list[tunnel_in_cell] = NULL;
    return tunnels_list;
}

/*!
 * init the tunnels for each cell of the table
 * @param cells: table of cell structure
 * @param parsing_info: structure which as been filled with the datas during
 * the parsing
*/
void init_tunnels(cell_t **cells, parsing_info_t *parsing_info)
{
    for (int i = 0; cells[i]; i++)
        cells[i]->tunnels = get_tunnels(cells[i]->name, cells,
            parsing_info->tunnel_list);
}
