/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-mysokoban-ines.maaroufi
** File description:
** lib_functions2
*/

#include "my_sokoban.h"

int my_strlen_n(char *path)
{
    int i = 0;

    for (; path[i]; i++)
        if (path[i] == '\n')
            break;
    return i;
}

int count_n(char *path)
{
    int count = 0;

    for (int i = 0; path[i]; i++)
        if (path[i] == '\n')
            count++;
    return count;
}

char *my_strncpy( char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

void fill_map(char *path, int offset, int count, char **arg)
{
    int count_sep = count_n(path);

    for (int i = 0; i < count_sep + 1; i++) {
        count = my_strlen_n(path + offset);
        my_strncpy(arg[i], path + offset, count);
        offset += count + 1;
    }
}

char **my_str_to_word_array(char *path)
{
    int count_sep = count_n(path);
    int count;
    int offset = 0;
    char **arg = NULL;

    arg = malloc(sizeof(char *) * (count_sep + 2));
    if (!arg)
        return (NULL);
    for (int i = 0; i < count_sep + 1; i++) {
        count = my_strlen_n(path + offset);
        arg[i] = malloc(sizeof(char) * (count + 1));
        if (!arg[i])
            return (NULL);
        offset += count + 1;
    }
    offset = 0;
    fill_map(path, offset, count, arg);
    arg[count_sep + 1] = NULL;
    return arg;
}