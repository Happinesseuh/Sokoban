/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** handle_map
*/

#include "my_sokoban.h"

int is_valide_map(char *map)
{
    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] != '\n' && map[i] != '#' && map[i] != 'X' &&
            map[i] != 'P' && map[i] != 'O' && map[i] != ' ') {
            return (1);
        }
    return (0);
}

int handle_map(char *map)
{
    int storage = 0;
    int boxes = 0;
    int player = 0;

    if (map == NULL)
        return (1);
    if (is_valide_map(map) == 1)
        return (1);
    for (int i = 0; map[i] != '\0'; i++) {
        if (map[i] == 'O')
            storage += 1;
        if (map[i] == 'X')
            boxes += 1;
        if (map[i] == 'P')
            player += 1;
    }
    if (storage != boxes || player != 1)
        return (1);
    return (0);
}