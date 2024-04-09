/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** parse_file.c
*/

#include "../include/amazed.h"

/*!
 * check if the number of robot is correct
 * @param table_parsing: parsing structure
 * @param parsing_info: line containing the number of robot
 * @return  if error -1 or 0
*/
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

/*!
 * call the parsing function of the cells and tunnels
 * @param parsing_info: parsing structure
 * @param table_parsing: table containing all input lines
 * @param index: address of the index to check
 * @return 84 or 0
*/
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

/*!
 * call the function to parse the number of robot and the cells and tunnels
 * @param parsing_info: parsing structure
 * @param table_parsing: table containing lines input
 * @return 0 or 84
*/
int parse_file(parsing_info_t *parsing_info, char ***table_parsing)
{
    int index = 1;

    if (check_nbr_robots(table_parsing[0], parsing_info) == -1) {
        return 84;
    }
    return parse_cell_and_tunnel(parsing_info, table_parsing, &index);
}
