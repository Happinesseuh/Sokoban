/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** move_box
*/

#include "my_sokoban.h"

char **move_box_right(char **map, position_t *pos, int key)
{
    int x = 0;
    int y = 0;

    if (key == KEY_RIGHT) {
        x = pos->player_x - 1;
        y = pos->player_y;
        check_storage(map[pos->player_y][pos->player_x + 1], pos);
        if (map[pos->player_y][pos->player_x + 1] != '#'
            && map[pos->player_y][pos->player_x + 1] != 'X') {
            map[pos->player_y][pos->player_x + 1] = 'X';
            map[pos->player_y][pos->player_x] = 'P';
            map[pos->player_y][pos->player_x - 1] = ' ';
            if (pos->map_copy[y][x] == 'O')
                map[y][x] = 'O';
        }
    }
    return (map);
}

char **move_box_left(char **map, position_t *pos, int key)
{
    int x = 0;
    int y = 0;

    if (key == KEY_LEFT) {
        x = pos->player_x + 1;
        y = pos->player_y;
        check_storage(map[pos->player_y][pos->player_x - 1], pos);
        if (map[pos->player_y][pos->player_x - 1] != '#'
            && map[pos->player_y][pos->player_x - 1] != 'X') {
            map[pos->player_y][pos->player_x - 1] = 'X';
            map[pos->player_y][pos->player_x] = 'P';
            map[pos->player_y][pos->player_x + 1] = ' ';
            if (pos->map_copy[y][x] == 'O')
                map[y][x] = 'O';
        }
    }
    return (map);
}

char **move_box_down(char **map, position_t *pos, int key)
{
    int x = 0;
    int y = 0;

    if (key == KEY_DOWN) {
        x = pos->player_x;
        y = pos->player_y - 1;
        check_storage(map[pos->player_y + 1][pos->player_x], pos);
        if (map[pos->player_y + 1][pos->player_x] != '#'
            && map[pos->player_y + 1][pos->player_x] != 'X') {
            map[pos->player_y + 1][pos->player_x] = 'X';
            map[pos->player_y][pos->player_x] = 'P';
            map[pos->player_y - 1][pos->player_x] = ' ';
            if (pos->map_copy[y][x] == 'O')
                map[y][x] = 'O';
        }
    }
    return (map);
}

char **move_box_up(char **map, position_t *pos, int key)
{
    int x = 0;
    int y = 0;

    if (key == KEY_UP) {
        x = pos->player_x;
        y = pos->player_y + 1;
        check_storage(map[pos->player_y - 1][pos->player_x], pos);
        if (map[pos->player_y - 1][pos->player_x] != '#'
            &&  map[pos->player_y - 1][pos->player_x] != 'X') {
            map[pos->player_y - 1][pos->player_x] = 'X';
            map[pos->player_y][pos->player_x] = 'P';
            map[pos->player_y + 1][pos->player_x] = ' ';
            if (pos->map_copy[y][x] == 'O')
                map[y][x] = 'O';
        }
    }
    return (map);
}

char **move_box(char **map, position_t *pos, int key)
{
    map = move_box_up(map, pos, key);
    map = move_box_down(map, pos, key);
    map = move_box_right(map, pos, key);
    map = move_box_left(map, pos, key);
    return (map);
}