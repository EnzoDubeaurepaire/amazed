/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** main.c
*/

/*!
 * @file main.c
*/

#include "../include/amazed.h"

/*!
 * do the parsing of all the input
 * @param table_file table of char * where each one is a char * given in input
 * @param table_parsing the adresse to initialise the table of char ** for
 * the parsing
 * @param parsing_info main struct for the parsing
 * @return return 0 if no error, 84 if major error or 1 if minor error
*/
int parsing(char **table_file, char ****table_parsing,
    parsing_info_t **parsing_info)
{
    if (table_file == NULL || table_file[0] == NULL)
        return 84;
    (*table_parsing) = create_3d_array_for_parsing(table_file);
    if ((*table_parsing) == NULL)
        return 84;
    (*parsing_info) = init_struct_parsing();
    if ((*parsing_info) == NULL)
        return 84;
    if (parse_file((*parsing_info), (*table_parsing)) == 84)
        return 1;
    return 0;
}

/*!
 *
 * @param parsing_info
 * @return
*/
static robots_info_t *init_robots_info(parsing_info_t *parsing_info)
{
    robots_info_t *robots_info = malloc(sizeof(robots_info_t));

    robots_info->robots_nb = parsing_info->robot_nb;
    robots_info->moved_robots = malloc(sizeof(u_int64_t) *
        my_ceil((double)robots_info->robots_nb / 64.0));
    return robots_info;
}

/*!
 * check the value of the parsing struct to see if error and print the file
 * @param parsing_info is the structure for the parsing
 * @return 84 if error or 0
*/
static int handling_error(parsing_info_t *parsing_info)
{
    if (parsing_info == NULL)
        return 84;
    if (parsing_info->start != 1 || parsing_info->end
        != 1 || parsing_info->tunnel_list == NULL || parsing_info->cell_list
        == NULL || parsing_info->robot_nb == 0) {
        print_file(parsing_info);
        return 84;
    }
    return 0;
}

/*!
 * main function of the program execute everything
 * @return either 0 or 84
*/
int main(void)
{
    char **table_file = check_stdin();
    char ***table_parsing;
    parsing_info_t *parsing_info = NULL;
    cell_t **cells;
    robots_info_t *robots_info;

    parsing(table_file, &table_parsing, &parsing_info);
    if (handling_error(parsing_info) == 84)
        return 84;
    print_file(parsing_info);
    cells = init_cells(parsing_info);
    init_tunnels(cells, parsing_info);
    robots_info = init_robots_info(parsing_info);
    return game_loop(cells, robots_info);
}
