/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../include/amazed.h"

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

static int is_comment(char *str)
{
    if (str[0] == '#')
        if (my_strcmp(str, "##start\n\0") != 0 && my_strcmp(str, "##end\n\0")
            != 0)
            return 1;
    return 0;
}

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
