/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** parse_tunnel.c
*/

/*!
 * @file parse_tunnel.c
*/

#include "../include/amazed.h"

/*!
 * check in cell list if the name of the tunnel are correct
 * @param parsing_info: parsing structure
 * @param name: name of the cell
 * @return 0 or 84
*/
static int check_in_cell_list(parsing_info_t *parsing_info, char const *name)
{
    cell_parsing_info_t *cell = parsing_info->cell_list;

    for (; cell != NULL; cell = cell->next) {
        if (my_strcmp(name, cell->name) == 0) {
            cell->tunnel_nb += 1;
            return 0;
        }
    }
    return 84;
}

/*!
 * call the function to check the names cell and add the tunnel to the list
 * in the structure parsing
 * @param parsing_info: parsing structure
 * @param first_tunnel: name of the first cell
 * @param second_tunnel: name of the second cell
 * @return 0 or 84
*/
static int check_if_name_exist(parsing_info_t *parsing_info,
    char *first_tunnel, char *second_tunnel)
{
    if (check_in_cell_list(parsing_info, first_tunnel) == 84 ||
        check_in_cell_list(parsing_info, second_tunnel) == 84)
        return 84;
    if (add_tunnel(parsing_info, first_tunnel, second_tunnel) == 84)
        return 84;
    return 0;
}

/*!
 * get the name of the
 * @param parsing_info
 * @param tunnel_info
 * @return
*/
static int check_if_valid_tunnel(parsing_info_t *parsing_info,
    char const *tunnel_info)
{
    char *first_tunnel = get_first_name(tunnel_info);
    char *second_tunnel;

    if (first_tunnel == NULL)
        return 84;
    second_tunnel = get_second_name(tunnel_info);
    if (second_tunnel == NULL) {
        free(first_tunnel);
        return 84;
    }
    if (check_if_name_exist(parsing_info, first_tunnel, second_tunnel) == 84) {
        free(first_tunnel);
        free(second_tunnel);
        return 84;
    }
    return 0;
}

/*!
 *
 * @param parsing_info
 * @param table_parsing
 * @param index
 * @return
*/
int parse_tunnel(parsing_info_t *parsing_info, char ***table_parsing,
    int *index)
{
    int value = 0;

    for (; table_parsing[*index] != NULL && value == 0; (*index)++) {
        if (get_len_stwa(table_parsing[(*index)]) != 1)
            return 84;
        value = check_if_valid_tunnel(parsing_info, table_parsing[*index][0]);
    }
    return value;
}
