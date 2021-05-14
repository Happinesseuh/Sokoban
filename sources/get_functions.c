/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** get_functions
*/

#include "my_sokoban.h"

void get_pos_player(char **map, position_t *pos)
{
    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'P') {
                pos->player_x = j;
                pos->player_y = i;
            }
        }
}

int get_nb_storage(char **map)
{
    int nb_storage = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'O')
                nb_storage += 1;
        }
    return (nb_storage);
}

void get_col_lines(char **map, position_t *pos)
{
    pos->nb_col = 0;
    for (pos->nb_lines = 0; map[pos->nb_lines] != NULL; pos->nb_lines++);
    for (int i = 0; map[i] != NULL; i++)
        if (my_strlen(map[i]) > pos->nb_col)
            pos->nb_col = my_strlen(map[i]);
}