/*
** EPITECH PROJECT, 2022
** main
** File description:
** main -> BSBSQ
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int bsq(char *);
int mini_printf(const char *format, ...);
char **my_str_to_word_array(char *b_tab);
void verif_bsq(char **tab);
void generate_map(char *av[]);
int	my_getnbr(char const *str);
int my_strlen(char const *str);

int read_bsq(char *av[])
{
    struct stat st;
    stat(av[1], &st);
    char *file = malloc(sizeof(char) * (st.st_size + 1));
    int fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return 84;
    read(fd, file, st.st_size);
    file[st.st_size] = '\0';
    close(fd);
    char **B_file = my_str_to_word_array(file);
    int deb = 0;
    for (; file[deb] != '\n'; deb++)
        deb += 0;
    for (int a = deb + 1; file[a] != '\0'; a++){
        if (file[a] != 'o' && file[a] != '.' && file[a] != '\n')
            return 84;
    } verif_bsq(B_file);
    free(file);
    free(B_file);
    return 0;
}

int verif2(char **av)
{
    int av1 = my_getnbr(av[1]) + 1;
    if (av1 <= 0)
        return 84;
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] != '.' && av[2][i] != 'o')
            return 84;
    }
    return 0;
}

int main(int ac, char *av[])
{
    if (ac == 2) {
        int verif1 = read_bsq(av);
        if (verif1 == 84)
            return 84;
        return 0;
    } if (ac == 3) {
        if (verif2(av) == 84)
            return 84;
        generate_map(av);
        return 0;
    } else {
        mini_printf("Error argument\n");
        return 84;
    }
    return 0;
}
