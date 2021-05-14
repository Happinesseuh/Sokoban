/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-bsmysokoban-ines.maaroufi
** File description:
** main
*/

#include "my_sokoban.h"

int my_putstr(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        write(1, &str[x],  1);
        x++;
    }
    return x;
}

void free_arr(char ** map)
{
    for (int i = 0; map[i] != NULL; i++)
            free(map[i]);
    free(map);
}

int error_handle(int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (ac == 2 && my_strcmp("-h", av[1]) == 0) {
        my_putstr("USAGE\n");
        my_putstr("\t./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("\tmap  file representing the warehouse map,");
        my_putstr(" containing ‘#’ for walls,\n");
        my_putstr("\t\t‘P’ for the player, ‘X’");
        my_putstr("for boxes and ‘O’ for storage locations.\n");
    }
    return (0);
}

char *read_map(char *path)
{
    int fd = 0;
    struct stat stack;
    char *buffer = NULL;
    int len = 0;

    fd = open(path, O_RDONLY);
    if (fd == -1)
        return (NULL);
    if (stat(path, &stack))
        return (NULL);
    buffer = malloc(sizeof(char) * stack.st_size + 1);
    len = read(fd, buffer, stack.st_size + 1);
    if (len == -1)
        return (NULL);
    buffer[len] = '\0';
    return (buffer);
}

int main(int ac, char **av)
{
    char *map = NULL;
    char **map_double = NULL;
    position_t pos;

    if (error_handle(ac, av) == 1)
        return (84);
    map = read_map(av[1]);
    if (handle_map(map) == 1)
        return (84);
    map_double = my_str_to_word_array(map);
    pos.map_copy = my_str_to_word_array(map);
    set_loop_game(map_double, &pos);
    if (pos.is_win == 1)
        return (0);
    if (pos.is_lose == 1)
        return (1);
    free_arr(map_double);
    free_arr(pos.map_copy);
}