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
    #define MAX_FILE_LENGTH 262144
    #define BUFFER_SIZE 131072

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
    char *buffer;
    size_t buffer_size;
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

/*
 * fill_tab_stdin.c
*/
char **check_stdin(void);

/*
 * create_stwa_for_each_line.c
*/
int get_len_stwa(char **file);
char ***create_3d_array_for_parsing(char **file);


/*
 * struct cell parsing
*/
typedef struct cell_parsing_info {
    size_t tunnel_nb;
    char *name;
    _Bool start;
    _Bool end;
    int coord_x;
    int coord_y;
    struct cell_parsing_info *next;
} cell_parsing_info_t;

/*
 * tunnel name
*/
typedef struct tunnel_name {
    char *name1;
    char *name2;
    struct tunnel_name *next;
} tunnel_t;

/*
 * struct parsing
*/
typedef struct parsing_info {
    size_t cell_nb;
    size_t robot_nb;
    _Bool start;
    _Bool end;
    cell_parsing_info_t *cell_list;
    tunnel_t *tunnel_list;
} parsing_info_t;

/*
 * init_parsing_struct.c
*/
parsing_info_t *init_struct_parsing(void);
int add_cell(char **cell_info, parsing_info_t *parsing_info, int type);
int add_tunnel(parsing_info_t *parsing_info, char *first_name,
    char *second_name);

/*
 * free_parsing.c
*/
void free_stwa(char **stwa);

/*
 * parse_cell.c
*/
int parse_cell(parsing_info_t *parsing_info, char ***table_parsing,
    int *index);

/*
 * parse_file.c
*/
int parse_file(parsing_info_t *parsing_info, char ***table_parsing);

/*
 * parse_tunnel.c
*/
int parse_tunnel(parsing_info_t *parsing_info, char ***table_parsing,
    int *index);

/*
 * get_names_tunnel.c
*/
char *get_first_name(char const *tunnel_info);
char *get_second_name(char const *tunnel_info);

/*
 * print_file.c
*/
void print_file(parsing_info_t *parsing_info);

/*
 * init_cells.c
*/
cell_t **init_cells(parsing_info_t *parsing_info);
void init_tunnels(cell_t **cells, parsing_info_t *parsing_info);

/*
 * write_to_buffer
*/
void write_to_buffer(robots_info_t *robots_info, char *to_write);

#endif //AMAZED_AMAZED_H
