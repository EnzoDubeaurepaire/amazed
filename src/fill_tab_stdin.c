/*
** EPITECH PROJECT, 2023
** rr
** File description:
** rr
*/

#include "../include/amazed.h"

int is_comment(char *str)
{
    if (str[0] == '#')
        if (my_strcmp(str, "##start\n\0") != 0 && my_strcmp(str, "##end\n\0")
            != 0)
            return 1;
    return 0;
}

char **check_stdin(void)
{
    char *tab[MAX_FILE_LENGTH] = {NULL};
    char **all_lines;
    size_t len = 0;
    ssize_t read = 0;
    char *line = NULL;
    int i = 0;

    for (read = getline(&line, &len, stdin); read >= 0; read =
        getline(&line, &len, stdin))
        if (is_comment(tab[i]) == 0) {
            tab[i] = my_strdup(line);
            i++;
        }
    if (line)
        free(line);
    all_lines = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; tab[j]; j++)
        all_lines[j] = tab[j];
    all_lines[i + 1] = NULL;
    return all_lines;
}
