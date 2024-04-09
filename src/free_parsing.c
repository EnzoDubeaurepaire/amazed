/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** free_parsing.c
*/

/*!
 * @file free_parsing.c
*/


#include "../include/amazed.h"

/*!
 * free a char **
 * @param stwa
*/
void free_stwa(char **stwa)
{
    for (int i = 0; stwa[i] != NULL; ++i) {
        free(stwa[i]);
    }
    free(stwa);
}
