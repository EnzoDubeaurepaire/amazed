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

int main(void)
{
    char **table_file = check_stdin();
    char ***table_parsing;
    parsing_info_t *parsing_info;
//    cell_t **table_cells = malloc(sizeof(cell_t *) * (nb_cell + 1));

    parsing(table_file, &table_parsing, &parsing_info);
    print_file(parsing_info);
    return 0;
}
