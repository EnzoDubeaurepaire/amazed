/*
** EPITECH PROJECT, 2024
** amazed_mirror
** File description:
** main.c
*/

#include "../include/amazed.h"

int parsing(char **table_file, char ****table_parsing,
    parsing_info_t **parsing_info)
{
    if (table_file == NULL)
        return 84;
    (*table_parsing) = create_3d_array_for_parsing(table_file);
    if ((*table_parsing) == NULL)
        return 84;
    (*parsing_info) = init_struct_parsing();
    if ((*parsing_info) == NULL)
        return 84;
    if (parse_file((*parsing_info), (*table_parsing)) == 84)
        return 84;
    return 0;
}

static robots_info_t *init_robots_info(parsing_info_t *parsing_info)
{
    robots_info_t *robots_info = malloc(sizeof(robots_info_t));

    robots_info->robots_nb = parsing_info->robot_nb;
    robots_info->moved_robots = malloc(sizeof(u_int64_t) *
        my_ceil((double)robots_info->robots_nb / 64.0));
    return robots_info;
}

int main(void)
{
    char **table_file = check_stdin();
    char ***table_parsing;
    parsing_info_t *parsing_info;
    cell_t **cells;
    robots_info_t *robots_info;

    parsing(table_file, &table_parsing, &parsing_info);
    print_file(parsing_info);
    cells = init_cells(parsing_info);
    init_tunnels(cells, parsing_info);
    robots_info = init_robots_info(parsing_info);
    game_loop(cells, robots_info);
    return 0;
}
