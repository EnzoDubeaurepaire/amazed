/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** free_parsing.c
*/

#include "../include/amazed.h"

void free_stwa(char **stwa)
{
    for (int i = 0; stwa[i] != NULL; ++i) {
        free(stwa[i]);
    }
    free(stwa);
}
