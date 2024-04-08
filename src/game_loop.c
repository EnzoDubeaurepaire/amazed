/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** game_loop.c
*/

#include "../include/amazed.h"

void write_to_buffer(robots_info_t *robots_info, char *to_write)
{
    size_t len = my_strlen(to_write);

    if (len + robots_info->buffer_size > BUFFER_SIZE) {
        write(1, robots_info->buffer, robots_info->buffer_size);
        robots_info->buffer_size = 0;
    }
    my_strcpy(robots_info->buffer + robots_info->buffer_size, to_write);
    robots_info->buffer_size += len;
}

static cell_t *get_start_cell(cell_t **cells)
{
    for (int i = 0; cells[i]; i++) {
        if (cells[i]->state == START)
            return cells[i];
    }
    return NULL;
}

static void move_all_robots(robots_info_t *robots_info, cell_t *end)
{
    char *str_nb;

    for (size_t i = 0; (size_t)i < end->robots_nb; i++) {
        if (i != 0)
            write_to_buffer(robots_info, " \0");
        write_to_buffer(robots_info, "P\0");
        str_nb = my_nb_to_str((long)i + 1);
        write_to_buffer(robots_info, str_nb);
        free(str_nb);
        write_to_buffer(robots_info, "-\0");
        write_to_buffer(robots_info, end->name);
    }
    write_to_buffer(robots_info, "\n\0");
}

void game_loop(cell_t **cells, robots_info_t *robots_info)
{
    get_move_to_end(cells);
    robots_info->robots_end = 0;
    robots_info->buffer = malloc(BUFFER_SIZE);
    if (get_start_cell(cells)->move_to_end == -1)
        return;
    if (get_start_cell(cells)->move_to_end == 1) {
        move_all_robots(robots_info, get_end_cell(cells));
        write(1, robots_info->buffer, robots_info->buffer_size);
        free(robots_info->buffer);
        return;
    }
    while (1) {
        move_robots(cells, robots_info);
        write_to_buffer(robots_info, "\n\0");
        if (is_end(cells)) {
            write(1, robots_info->buffer, robots_info->buffer_size);
            free(robots_info->buffer);
            return;
        }
    }
}
