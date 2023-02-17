/*
** EPITECH PROJECT, 2022
** generate_map
** File description:
** generate_map
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int my_strlen(char const *str);
int mini_printf(const char *format, ...);
void verif_bsq(char **tab);

int	my_getnbr(char const *str)
{
    int neg = 1;
    long nb = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 45)
            neg = neg * -1;
        if (str[i] >= 48 && str[i] <= 57)
            nb = nb * 10 + (str[i] - 48);
        nb = nb * neg;
        if (nb < -2147483648 || nb > 2147483647) {
            mini_printf("Nombre trop grand dans get_nbr !\n");
            return 0;
        } nb = nb * neg;
    } int result = nb * neg;
    return result;
}

int verif(int a, int size)
{
    if (a == size)
        return 0;
    else
        return a;
}

void generate_map(char **av)
{
    int size = my_strlen(av[2]);
    int av1 = my_getnbr(av[1]) + 1;
    char **file = malloc(sizeof(char*) * av1 + 1);
    int a = 0;
    for (int y = 1; y < av1; y++){
        file[y] = malloc(sizeof(char) * av1 + 1);
        for (int x = 0; x < av1 - 1; x++) {
            a = verif(a, size);
            file[y][x] = av[2][a];
            a++;
        }
    } verif_bsq(file);
    for (int y = 0; y < av1; y++)
        free(file[y]);
    free(file);
}
