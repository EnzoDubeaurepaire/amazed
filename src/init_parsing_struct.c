/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** init_parsing_struct.c
*/

#include "../include/amazed.h"

parsing_info_t *init_struct_parsing(void)
{
    parsing_info_t *init_struct = malloc(sizeof(parsing_info_t));

    if (init_struct == NULL)
        return NULL;
    init_struct->end = 0;
    init_struct->start = 0;
    init_struct->cell_nb = 0;
    init_struct->robot_nb = 0;
    init_struct->cell_list = NULL;
    init_struct->tunnel_list = NULL;
    return init_struct;
}

int add_cell(char **cell_info, parsing_info_t *parsing_info, int type)
{
    cell_parsing_info_t *new = malloc(sizeof(cell_parsing_info_t));
    cell_parsing_info_t *cell = parsing_info->cell_list;

    if (new == NULL)
        return 84;
    new->name = cell_info[0];
    new->coord_x = my_atoi(cell_info[1]);
    new->coord_y = my_atoi(cell_info[2]);
    new->next = NULL;
    if (type == START)
        new->start = 1;
    if (type == END)
        new->end = 1;
    if (parsing_info->cell_list == NULL) {
        parsing_info->cell_list = new;
        return 0;
    }
    for (; cell->next != NULL; cell = cell->next);
    cell->next = new;
    return 0;
}

int add_tunnel(parsing_info_t *parsing_info, char *first_name,
    char *second_name)
{
    tunnel_t *new = malloc(sizeof(tunnel_t));
    tunnel_t *tunnel = parsing_info->tunnel_list;

    if (new == NULL)
        return 84;
    new->name1 = first_name;
    new->name2 = second_name;
    new->next = NULL;
    if (parsing_info->tunnel_list == NULL) {
        parsing_info->tunnel_list = new;
        return 0;
    }
    for (; tunnel->next != NULL; tunnel = tunnel->next);
    tunnel->next = new;
    return 0;
}
