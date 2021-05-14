/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-bsmysokoban-ines.maaroufi
** File description:
** my_sokoban
*/

#ifndef MY_SOKOBAN_H_
#define MY_SOKOBAN_H_

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ncurses.h>

typedef struct positions_s {
    int player_x;
    int player_y;
    int storage;
    int is_win;
    int is_lose;
    int nb_lines;
    int nb_col;
    char **map_copy;
}position_t;

/* CHECK FUNCTIONS */
void check_storage(char c, position_t *pos);
int check_size(position_t *pos);
int box_is_blocked(char **map, int i, int j);
void is_win(char **map, position_t *pos, int nb_storage);
void check_box_blocked(char **map, position_t *pos);
/* GET FUNCTIONS */
void get_pos_player(char **map, position_t *pos);
int get_nb_storage(char **map);
void get_col_lines(char **map, position_t *pos);
/* HANDLE MAP */
int is_valide_map(char *map);
int handle_map(char *map);
/* LOOP GAME */
void disp_map(char **map, position_t *pos);
void loop_game(int nb_storage, position_t *pos, char **map);
int set_loop_game(char **map, position_t *pos);
/* MOVE BOX */
char **move_box_right(char **map, position_t *pos, int key);
char **move_box_left(char **map, position_t *pos, int key);
char **move_box_down(char **map, position_t *pos, int key);
char **move_box_up(char **map, position_t *pos, int key);
char **move_box(char **map, position_t *pos, int key);
/* MOVE PLAYER */
void key_pressed(int key, position_t *pos);
char **move_player(char **map, position_t *pos, int erased_x, int erased_y);
char **move_player_or_box(char **map, position_t *pos, int key, int nb_storage);
/* MAIN */
int error_handle(int ac, char **av);
char *read_map(char *path);
/* LIB */
int my_strlen(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_show_word_array(char * const *tab);
char **my_str_to_word_array(char *path);
char **tabdup(char **env);
int my_strcmp(char const *s1, char const *s2);
void free_arr(char ** map);
char *my_strdup(char const *src);
char *my_strcpy(char *dest, char const *src);

#endif /* !MY_SOKOBAN_H_ */