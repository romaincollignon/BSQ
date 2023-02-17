/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** Project bsq
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int bsq(char *);
int mini_printf(const char *format, ...);
char *read_file(char *name_file);
char *change_file(int x, int y, int length, char *file);
int my_strlen(char const *str);

int test(int x, int y, char **tab, int size)
{
    for (int x2 = 0; x2 <= size; x2++) {
        if (tab[y] == NULL || tab[y][x + x2] != '.') {
            return size;
        }
    }
    return (-1);
}

int cherch_bsq(int x, int y, int size, char **tab)
{
    int tmp = 0;

    for (int y2 = 0; y2 <= size; y2++) {
        tmp = test(x, y + y2, tab, size);
        if (tmp != -1) {
            return (size);
        }
    }
    return cherch_bsq(x, y, size + 1, tab);
}

void change_file_a(int save_y, int save_x, int size, char **tab)
{
    int max_x = save_x + size;
    int max_y = save_y + size;
    for (int a = save_x; a < max_x; a++) {
        for (int i = save_y; i < max_y; i++) {
            tab[i][a] = 'x';
        }
    }
    for (int n = 1; tab[n] != NULL; n++)
        mini_printf("%s\n", tab[n]);
}

void verif_bsq(char **tab)
{
    int save_x = 0;
    int save_y = 0;
    int save_size = 0;
    for (int y = 1, size = 0; tab[y] != NULL; y++) {
        for (int x = 0; tab[y][x] != '\0'; x++) {
            size = tab[y][x] == '.' ? cherch_bsq(x, y, 0, tab) : 0;
            save_x = save_size < size ? x : save_x;
            save_y = save_size < size ? y : save_y;
            save_size = save_size < size ? size : save_size;
        }
    }
    change_file_a(save_y, save_x, save_size, tab);
}
