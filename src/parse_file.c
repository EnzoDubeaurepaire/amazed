/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** parse_file.c
*/

#include "../include/amazed.h"

static int check_nbr_robots(char **table_parsing, parsing_info_t *parsing_info)
{
    if (table_parsing[0] == NULL || get_len_stwa(table_parsing) != 1)
        return -1;
    for (int i = 0; table_parsing[0][i] != '\0'; i++)
        if (table_parsing[0][i] < '0' || table_parsing[0][i] > '9')
            return -1;
    parsing_info->robot_nb = my_atoi(table_parsing[0]);
    return 0;
}

int parse_cell_and_tunnel(parsing_info_t *parsing_info, char ***table_parsing,
    int *index)
{
    int value = parse_cell(parsing_info, table_parsing, index);

    if (value == 84) {
        return 84;
    }
    if (value == 0)
        return 84;
    if (parse_tunnel(parsing_info, table_parsing, index) == 84) {
        return 84;
    }
    return 0;
}

int parse_file(parsing_info_t *parsing_info, char ***table_parsing)
{
    int index = 1;

    if (check_nbr_robots(table_parsing[0], parsing_info) == -1) {
        return 84;
    }
    return parse_cell_and_tunnel(parsing_info, table_parsing, &index);
}
