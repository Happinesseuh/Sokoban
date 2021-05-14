/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** move_objects
*/

#include "my_sokoban.h"

void key_pressed(int key, position_t *pos)
{
    if (key == KEY_LEFT)
        pos->player_x -= 1;
    if (key == KEY_RIGHT)
        pos->player_x += 1;
    if (key == KEY_UP)
        pos->player_y -= 1;
    if (key == KEY_DOWN)
        pos->player_y += 1;
}

char **move_player(char **map, position_t *pos, int erased_x, int erased_y)
{
    if (pos->map_copy[erased_y][erased_x] == 'O')
        map[erased_y][erased_x] = 'O';
    else
        map[erased_y][erased_x] = ' ';
    map[pos->player_y][pos->player_x] = 'P';
    return (map);
}

char **move_player_or_box(char **map, position_t *pos, int key, int nb_storage)
{
    int x = 0;
    int y = 0;

    get_pos_player(map, pos);
    x = pos->player_x;
    y = pos->player_y;
    key_pressed(key, pos);
    if (map[pos->player_y][pos->player_x] == '#') {
        pos->player_x = x;
        pos->player_y = y;
        return (map);
    } else if (map[pos->player_y][pos->player_x] == 'X')
        map = move_box(map, pos, key);
    else
        map = move_player(map, pos, x, y);
    is_win(map, pos, nb_storage);
    check_box_blocked(map, pos);
    return (map);
}