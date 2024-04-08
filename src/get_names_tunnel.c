/*
** EPITECH PROJECT, 2023
** amazed_mirror
** File description:
** get_names_tunnel
*/

#include "../include/amazed.h"

char *get_first_name(char const *tunnel_info)
{
    char *name;
    int size = 0;

    for (; tunnel_info[size] != '\0'; size++)
        if (tunnel_info[size] == '-')
            break;
    if (tunnel_info[0] == '-' || size == my_strlen(tunnel_info))
        return NULL;
    name = malloc(sizeof(char) * (size + 1));
    if (name == NULL)
        return NULL;
    for (int i = 0; tunnel_info[i] != '-'; i++)
        name[i] = tunnel_info[i];
    name[size] = '\0';
    return name;
}

char *get_second_name(char const *tunnel_info)
{
    char *name;
    int size = 0;
    int i;

    for (; tunnel_info[size] != '\0'; size++)
        if (tunnel_info[size] == '-')
            break;
    if (tunnel_info[size + 1] == '\0')
        return NULL;
    for (i = size + 1; tunnel_info[i] != '\0'; i++);
    name = malloc(sizeof(char) * (i + 1));
    if (name == NULL)
        return NULL;
    size++;
    for (int j = 0; tunnel_info[size] != '\0'; j++) {
        name[j] = tunnel_info[size];
        size++;
    }
    name[i] = '\0';
    return name;
}
