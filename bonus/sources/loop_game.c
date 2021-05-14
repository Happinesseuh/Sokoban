/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** loop_game
*/

#include "my_sokoban.h"

void disp_map(char **map, position_t *pos)
{
    char *str = "resize";

    if (check_size(pos) == 1)
        mvprintw(LINES / 2, COLS / 2 - my_strlen(str) / 2, "%s", str);
    else
        for (int i = 0; map[i] != NULL; i++)
            mvprintw(LINES / 2 - pos->nb_lines / 2 + i,
                COLS / 2 - pos->nb_col / 2, "%s", map[i]);
}

void loop_game(int nb_storage, position_t *pos, char **map)
{
    int key = -1;

    while (1) {
        clear();
        disp_map(map, pos);
        key = getch();
        if (key == ' ')
            map = tabdup(pos->map_copy);
        map = move_player_or_box(map, pos, key, nb_storage);
        disp_map(map, pos);
        refresh();
        if (pos->is_win == 1)
            break;
        if (pos->is_lose == 1)
            break;
    }
}

void error_color(void)
{
    if (!has_colors()) {
        endwin();
        exit(84);
    }
}

int set_loop_game(char **map, position_t *pos)
{
    int nb_storage = get_nb_storage(map);

    get_col_lines(map, pos);
    initscr();
    error_color();
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    pos->storage = 0;
    pos->is_win = 0;
    pos->is_lose = 0;
    attron(COLOR_PAIR(1));
    loop_game(nb_storage, pos, map);
    attroff(COLOR_PAIR(1));
    curs_set(1);
    endwin();
    return (0);
}
