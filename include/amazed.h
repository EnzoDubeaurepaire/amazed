/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** amazed.h
*/

#ifndef AMAZED_AMAZED_H
    #define AMAZED_AMAZED_H
    #include "../lib/lib.h"

/*
 * cell max name length
*/
    #define MAX_NAME_LENGTH 2048

/*
 * state values
*/
    #define START 0
    #define END 1
    #define NONE 2

/*
 * cell structure
*/
typedef struct cell {
    u_char state;
    char name[MAX_NAME_LENGTH];
    ssize_t move_to_end;
    _Bool *robots;
    size_t robots_nb;
    struct cell **tunnels;
} cell_t;

/*
 * robots information
*/
typedef struct robots_info {
    size_t robots_nb;
    _Bool *moved_robots;
} robots_info_t;

/*
 * cell_is_valid.c
*/
_Bool can_go_to_cell(cell_t *cell);
_Bool cell_is_empty(cell_t *cell);

/*
 * cell_selection.c
*/
cell_t *select_cell_to_go(cell_t *actual_cell);

/*
 * move_robots.c
*/
void move_robots(cell_t **cells, robots_info_t *robots_info);

/*
 * check_end.c
*/
_Bool is_end(cell_t **cells);
cell_t *get_end_cell(cell_t **cells);

/*
 * game_loop.c
*/
void game_loop(cell_t **cells, robots_info_t *robots_info);

/*
 * free_cells.c
*/
void free_robots_info(robots_info_t *robots_info);
void free_cells(cell_t **cells);

/*
 * get_move_to_end.c
*/
void get_move_to_end(cell_t **cells);

#endif //AMAZED_AMAZED_H
