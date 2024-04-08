/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** parse_cell.c
*/

#include "../include/amazed.h"

static int is_valid_coord(char **cell_info, parsing_info_t *parsing_info)
{
    int x = my_atoi(cell_info[1]);
    int y = my_atoi(cell_info[2]);

    if (parsing_info->cell_list == NULL)
        return 0;
    for (cell_parsing_info_t *cell = parsing_info->cell_list; cell != NULL;
        cell = cell->next) {
        if (x == cell->coord_x && y == cell->coord_y)
            return 84;
    }
    return 0;
}

static int is_valid_name(char *str, parsing_info_t *parsing_info)
{
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '-')
            return 84;
    }
    if (parsing_info->cell_list == NULL)
        return 0;
    for (cell_parsing_info_t *cell = parsing_info->cell_list; cell != NULL;
        cell = cell->next) {
        if (my_strcmp(cell->name, str) == 0)
            return 84;
    }
    return 0;
}

static int check_valid_cell(char **table_parsing, parsing_info_t *parsing_info,
    int type)
{
    if (get_len_stwa(table_parsing) != 3) {
        if (type == 0)
            return 1;
        return 84;
    }
    if (is_valid_name(table_parsing[0], parsing_info) == 84)
        return 84;
    if (is_valid_coord(table_parsing, parsing_info) == 84)
        return 84;
    if (type == 1)
        parsing_info->start = 1;
    if (type == 2)
        parsing_info->end = 1;
    parsing_info->cell_nb += 1;
    return 0;
}

int check_type_cell(parsing_info_t *parsing_info, char ***table_parsing,
    int *index, int *type)
{
    if (my_strcmp(table_parsing[*index][0], "##start\0") == 0) {
        (*index)++;
        (*type) = START;
        return check_valid_cell(table_parsing[*index], parsing_info, START);
    } else if (my_strcmp(table_parsing[*index][0], "##end\0") == 0) {
        (*index)++;
        (*type) = END;
        return check_valid_cell(table_parsing[*index], parsing_info, END);
    }
    (*type) = NONE;
    return check_valid_cell(table_parsing[*index], parsing_info, NONE);
}

int check_len_stwa(char **cell_info)
{
    int len = get_len_stwa(cell_info);

    if (len != 3) {
        if (len == 1 && (my_strcmp(cell_info[0], "##start") == 0 ||
            my_strcmp(cell_info[0], "##end") == 0)) {
            return 0;
        }
        if (len == 1)
            return 1;
        return 84;
    }
    return 0;
}

int parse_cell(parsing_info_t *parsing_info, char ***table_parsing, int *index)
{
    int value;
    int type = 0;

    for (; table_parsing[*index] != NULL && value == 0; (*index)++) {
        value = check_len_stwa(table_parsing[*index]);
        if (value != 0)
            return value;
        value = check_type_cell(parsing_info, table_parsing, index, &type);
        if (value == 0 && add_cell(table_parsing[*index], parsing_info, type)
            == 84)
            value = 84;
    }
    if (parsing_info->start == 0 || parsing_info->end == 0)
        return 84;
    return value;
}
