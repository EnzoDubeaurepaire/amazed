/*
** EPITECH PROJECT, 2023
** create_stwa_for_each_line
** File description:
** create 3d array
*/

#include "../include/amazed.h"

int get_len_stwa(char **file)
{
    int size = 0;

    for (; file[size] != NULL; size++);
    return size;
}

char ***create_3d_array_for_parsing(char **file)
{
    int size = get_len_stwa(file);
    char ***file_parsing = malloc(sizeof(char **) * (size + 1));

    if (file_parsing == NULL)
        return NULL;
    file_parsing[size] = NULL;
    for (int i = 0; file[i] != NULL; i++) {
        file_parsing[i] = my_str_to_word_array(file[i]);
        if (file_parsing[i] == NULL)
            return NULL;
    }
    return file_parsing;
}
