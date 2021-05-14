/*
** EPITECH PROJECT, 2021
** B-PSU-200-PAR-2-1-bsmysokoban-ines.maaroufi
** File description:
** lib_functions
*/

#include "my_sokoban.h"

int my_strlen(char const *str)
{
    int x = 0;
    while (str[x] != '\0') {
        x++;
    }
    return x;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return (1);
        }else if (s1[i] < s2[i]) {
            return (-1);
        }
    }
    if (s1[i] == s2[i]) {
        return (0);
    }
    return (1);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0' ; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src)
{
    char *j = malloc(sizeof(src) * (my_strlen(src)));

    my_strcpy(j, src);
    return (j);
}

char **tabdup(char **env)
{
    int count = 0;
    char **new_env = NULL;

    for (count = 0; env[count] != NULL; count++);
    new_env = malloc(sizeof(char *) * count);
    for (count = 0; env[count] != NULL; count++) {
        new_env[count] = my_strdup(env[count]);
    }
    new_env[count] = NULL;
    return (new_env);
}