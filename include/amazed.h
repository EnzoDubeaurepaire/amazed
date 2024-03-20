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
    #define MAX_FILE_LENGTH 4096

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
    u_int64_t *robots;
    size_t robots_nb;
    struct cell **tunnels;
    size_t moved;
    _Bool has_robots;
    size_t robots_present;
    _Bool received;
} cell_t;

/*
 * robots information
*/
typedef struct robots_info {
    size_t robots_nb;
    u_int64_t *moved_robots;
    size_t robots_end;
} robots_info_t;


/*
 * cell_is_valid.c
*/
int can_go_to_cell(cell_t *cell);
int cell_is_empty(cell_t *cell);

/*
 * cell_selection.c
*/
cell_t *select_cell_to_go(cell_t *actual_cell);

/*
 * move_robots.c
*/
void move_robots(cell_t **cells, robots_info_t *robots_info);
void move_robot_in_cell(cell_t *cell, robots_info_t *robots_info,
    size_t robot, _Bool *first);

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

/*
 * cells_len.c
*/
size_t cells_len(cell_t **cells);

/*
 * check_name_cell.c
*/
cell_t *check_name_cell(cell_t **tab, char *name);

/*
 * init_cell_struct.c
*/
cell_t *init_cell(u_char state, char *name, size_t nb_robots);

/*
 * ceil.c
*/
int my_ceil(double nb);
int my_floor(double nb);

#endif //AMAZED_AMAZED_H
