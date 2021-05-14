/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** test_map
*/

#include  <criterion/criterion.h>
#include <stdlib.h>
#include "my_sokoban.h"
#define CTOI(x) (x - '0')

void free_arr(char ** map)
{
    for (int i = 0; map[i] != NULL; i++)
            free(map[i]);
    free(map);
}

Test(sokoban, load_map)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = my_str_to_word_array(map);

    cr_expect_str_eq(map2d[0], "#######");
    cr_expect_str_eq(map2d[1], "#   P #");
    cr_expect_str_eq(map2d[2], "#  X  #");
    cr_expect_str_eq(map2d[3], "#   O #");
    cr_expect_str_eq(map2d[4], "#######");
    for (int i = 0; map2d[i] != NULL; i++)
        free(map2d[i]);
    free(map2d);
}

Test(sokoban, lib)
{
    char const *src = "test";
    char *dest = malloc(sizeof(my_strlen(src)) + 1);
    char *result = my_strdup(src);
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **test = tabdup(my_str_to_word_array(map));

    cr_expect_eq(my_strlen("test"), 4);
    cr_expect_eq(my_strcmp("test", "test"), 0);
    cr_expect_eq(my_strcmp("test", "tests"), -1);
    cr_expect_eq(my_strcmp("tests", "test"), 1);
    cr_expect_str_eq(my_strcpy(dest, src), "test");
    cr_expect_str_eq(result, "test");
    //cr_expect_eq(my_str_to_word_array(map), test);
    free_arr(test);
}

Test(sokoban, get_player_pos)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char **map2d = my_str_to_word_array(map);
    position_t pos;

    pos.storage = 0;
    get_pos_player(map2d, &pos);
    cr_expect_eq(pos.player_x, 4);
    cr_expect_eq(pos.player_y, 1);
    check_storage('O', &pos);
    cr_expect_eq(pos.storage, 1);
    free_arr(map2d);
}

Test(sokoban, is_box_blocked)
{
    char *map = "#######\n#######\n#   XP#\n#   O #\n#######\n";
    char **map2d = my_str_to_word_array(map);

    cr_expect_eq(box_is_blocked(map2d, 0, 2), 1);
    cr_expect_eq(box_is_blocked(map2d, 3, 5), 2);
    cr_expect_eq(box_is_blocked(map2d, 2, 5), 3);
    cr_expect_eq(box_is_blocked(map2d, 2, 1), 4);
    cr_expect_eq(box_is_blocked(map2d, 3, 3), 0);
    free_arr(map2d);
}

Test(sokoban, check_is_box_blocked)
{
    char *map = "#######\n#     #\n\n#P    #\n#P    #\n#     #\n#O   O#\n#X   X#\n#######\n";
    char **map2d = my_str_to_word_array(map);
    position_t pos;

    pos.is_lose = 0;
    check_box_blocked(map2d, &pos);
    cr_expect_eq(pos.is_lose, 1);
    free_arr(map2d);
}

Test(sokoban, is_pos_storage)
{
    position_t pos;

    pos.storage = 0;
    check_storage('O', &pos);
    cr_expect_eq(pos.storage, 1);
}

Test(sokoban, map_handler)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######\n";
    char *bad_char_map = "3ù*rùĥyu\n#   P #\n#  X  #\n#   O #\n#######\n";
    char *bad_p_map = "#######\n#  PP #\n#  X  #\n#   O #\n#######\n";
    char *bad_storage_map = "#######\n#  OP #\n#  X  #\n#   O #\n#######\n";

    cr_expect_eq(is_valide_map(map), 0);
    cr_expect_eq(is_valide_map(bad_char_map), 1);
    cr_expect_eq(handle_map(bad_char_map), 1);
    cr_expect_eq(handle_map(NULL), 1);
    cr_expect_eq(handle_map(bad_p_map), 1);
    cr_expect_eq(handle_map(bad_storage_map), 1);
    cr_expect_eq(handle_map(map), 0);
}

Test(sokoban, get_lines_col)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######";
    char **map2d = my_str_to_word_array(map);
    position_t pos;

    get_col_lines(map2d, &pos);
    cr_expect_eq(pos.nb_lines, 5);
    cr_expect_eq(pos.nb_col, 7);
    free_arr(map2d);
}

Test(sokoban, win)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######";
    char *win = "#######\n#   P #\n#     #\n#   X #\n#######";
    char **map2d = my_str_to_word_array(win);
    int nb_storage = 1;
    position_t pos;

    pos.is_win = 0;
    pos.map_copy = my_str_to_word_array(map);
    is_win(map2d, &pos, nb_storage);
    cr_expect_eq(pos.is_win, 1);
    free_arr(map2d);
}

Test(sokoban, not_win)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######";
    char *not_win = "#######\n#   P #\n#   X #\n#   O #\n#######";
    char **map2d = my_str_to_word_array(not_win);
    int nb_storage = 1;
    position_t pos;

    pos.is_win = 0;
    pos.map_copy = my_str_to_word_array(map);
    is_win(map2d, &pos, nb_storage);
    cr_expect_eq(pos.is_win, 0);
    free_arr(map2d);
}

Test(sokoban, get_storage_nb)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######";
    char **map2d = my_str_to_word_array(map);

    cr_expect_eq(get_nb_storage(map2d), 1);
    free_arr(map2d);
}

Test(sokoban, player_mov)
{
    char *map = "#######\n#   P #\n#  X  #\n#   O #\n#######";
    char **map2d = my_str_to_word_array(map);
    position_t pos;

    pos.player_x = 1;
    pos.player_y = 1;

    key_pressed(KEY_LEFT, &pos);
    cr_expect_eq(pos.player_x, 0);
    key_pressed(KEY_RIGHT, &pos);
    cr_expect_eq(pos.player_x, 1);
    key_pressed(KEY_UP, &pos);
    cr_expect_eq(pos.player_y, 0);
    key_pressed(KEY_DOWN, &pos);
    cr_expect_eq(pos.player_y, 1);
    free_arr(map2d);
}

Test(sokoban, player_move)
{
    char *map = "#######\n#O  P #\n#  X  #\n#     #\n#######";
    char *map_copy = "#######\n#O  P #\n#  X  #\n#     #\n#######";
    char **map2d = my_str_to_word_array(map);
    position_t pos;

    pos.player_x = 4;
    pos.player_y = 1;
    pos.map_copy = my_str_to_word_array(map_copy);
    move_player(map2d, &pos, 1, 1);
    cr_assert_eq(map2d[1][1], 'O');
    move_player(map2d, &pos, 1, 2);
    cr_assert_eq(map2d[1][4], 'P');
    move_player(map2d, &pos, 1, 2);
    cr_assert_eq(map2d[1][2], ' ');
    free_arr(map2d);
}

Test(sokoban, move_anything)
{
    char *map_blocked = "#######\n#O   P#\n#  X  #\n#     #\n#######";
    char **map2d = my_str_to_word_array(map_blocked);
    position_t pos;

    pos.player_x = 0;
    pos.player_y = 0;
    pos.map_copy = my_str_to_word_array(map_blocked);
    move_player_or_box(map2d, &pos, KEY_RIGHT, 1);
    cr_expect_eq(map2d[pos.player_y][pos.player_x], 'P');
}

Test(sokoban, move_the_box)
{
    char *map_box = "#######\n#O PX #\n#     #\n#     #\n#######";
    char **map2d = my_str_to_word_array(map_box);
    position_t pos;

    pos.player_x = 0;
    pos.player_y = 0;
    pos.map_copy = my_str_to_word_array(map_box);
    move_player_or_box(map2d, &pos, KEY_RIGHT, 1);
    cr_expect_eq(map2d[1][5], 'X');
}

Test(sokoban, move_the_player)
{
    char *map_player = "#######\n#O P  #\n#  X  #\n#     #\n#######";
    char **map2d = my_str_to_word_array(map_player);
    position_t pos;

    pos.player_x = 0;
    pos.player_y = 0;
    pos.map_copy = my_str_to_word_array(map_player);
    move_player_or_box(map2d, &pos, KEY_RIGHT, 1);
}

Test(sokoban, size_check)
{
    position_t pos;

    pos.nb_lines = 5;
    pos.nb_col = 5;
    cr_expect_eq(check_size(&pos), 1);
    pos.nb_lines = 0;
    pos.nb_col = 5;
    cr_expect_eq(check_size(&pos), 1);
    pos.nb_lines = 0;
    pos.nb_col = 0;
    cr_expect_eq(check_size(&pos), 0);
}