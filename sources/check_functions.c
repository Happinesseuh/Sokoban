/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** get_pos
*/

#include "my_sokoban.h"

void check_storage(char c, position_t *pos)
{
    if (c == 'O') {
        pos->storage += 1;
    }
}

int check_size(position_t *pos)
{
    if (pos->nb_lines > LINES)
        return (1);
    if (pos->nb_col > COLS)
        return (1);
    return (0);
}

int box_is_blocked(char **map, int i, int j)
{
    if ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') &&
        (map[i + 1][j] == '#' || map[i + 1][j] == 'X'))
        return (1);
    if ((map[i][j + 1] == '#' || map[i][j + 1] == 'X') &&
        (map[i + 1][j] == '#' || map[i + 1][j] == 'X'))
        return (2);
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') &&
        (map[i][j + 1] == '#' || map[i][j + 1] == 'X'))
        return (3);
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') &&
        (map[i][j - 1] == '#' || map[i][j - 1] == 'X'))
        return (4);
    return (0);
}

void is_win(char **map, position_t *pos, int nb_storage)
{
    int win = 0;

    for (int i = 0; pos->map_copy[i] != NULL && map[i] != NULL; i++)
        for (int j = 0; pos->map_copy[i][j] != '\0' && map[i][j] != '\0'; j++)
            if (pos->map_copy[i][j] == 'O' && map[i][j] == 'X')
                win += 1;
    if (win == nb_storage)
        pos->is_win = 1;
}

void check_box_blocked(char **map, position_t *pos)
{
    int count = 0;
    int box = 0;

    for (int i = 0; map[i] != NULL; i++)
        for (int j = 0; map[i][j] != '\0'; j++) {
            if (map[i][j] == 'X' && box_is_blocked(map, i, j) != 0)
                count += 1;
            if (map[i][j] == 'X')
                box += 1;
        }
    if (count == box)
        pos->is_lose = 1;
}