/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

/*!
 * @file fill_tab_stdin.c
*/

#include "../include/amazed.h"

/*!
 * delete the comment in the input line
 * @param str is a input line
 * @return the str without comment
*/
static char *delete_comment_end_line(char *str)
{
    if (my_strcmp(str, "##start\n\0") == 0 || my_strcmp(str, "##end\n\0") == 0)
        return str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '#') {
            str[i] = '\0';
            break;
        }
    }
    return str;
}

/*!
 * check if all the line is a comment
 * @param str is a input line
 * @return 1 if a comment or 0 if isn't
*/
static int is_comment(char *str)
{
    if (str[0] == '#')
        if (my_strcmp(str, "##start\n\0") != 0 && my_strcmp(str, "##end\n\0")
            != 0)
            return 1;
    return 0;
}

/*!
 * collect the input values
 * @return char ** with where each line is a line given as an input
*/
char **check_stdin(void)
{
    char **tab = malloc(MAX_FILE_LENGTH * sizeof(char *));
    size_t len = 0;
    ssize_t read = 0;
    char *line = NULL;
    int i = 0;

    for (read = getline(&line, &len, stdin); read >= 0; read =
        getline(&line, &len, stdin))
        if (is_comment(line) == 0) {
            tab[i] = my_strdup(line);
            i++;
        }
    if (line)
        free(line);
    for (int j = 0; tab[j]; j++)
        tab[j] = delete_comment_end_line(tab[j]);
    return tab;
}
