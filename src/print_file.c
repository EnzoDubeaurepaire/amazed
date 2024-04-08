/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** print_file.c
*/

#include "../include/amazed.h"

void print_tunnels(parsing_info_t *parsing_info)
{
    write(1, "#tunnels\n", 9);
    for (tunnel_t *tunnel = parsing_info->tunnel_list; tunnel != NULL;
        tunnel = tunnel->next) {
        write(1, tunnel->name1, my_strlen(tunnel->name1));
        write(1, "-", 1);
        write(1, tunnel->name2, my_strlen(tunnel->name2));
        write(1, "\n", 1);
    }
}

void print_cells(parsing_info_t *parsing_info)
{
    write(1, "#rooms\n", 7);
    for (cell_parsing_info_t *cell = parsing_info->cell_list; cell != NULL;
        cell = cell->next) {
        if (cell->start == 1)
            write(1, "##start\n", 9);
        if (cell->end == 1)
            write(1, "##end\n", 7);
        write(1, cell->name, my_strlen(cell->name));
        write(1, " ", 1);
        my_putnbr(cell->coord_x);
        write(1, " ", 1);
        my_putnbr(cell->coord_y);
        write(1, "\n", 1);
    }
}

void print_file(parsing_info_t *parsing_info)
{
    write(1, "#number_of_robots\n", 18);
    my_putnbr(parsing_info->robot_nb);
    write(1, "\n", 1);
    print_cells(parsing_info);
    print_tunnels(parsing_info);
    write(1, "#moves\n", 8);
}
