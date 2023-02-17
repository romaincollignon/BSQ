##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC =	src/function/mini_printf.c \
		src/function/my_put_nbr.c \
		src/function/my_putchar.c \
		src/function/my_putstr.c \
		src/function/my_compute_power_rec.c \
		src/function/my_revstr.c \
		src/function/my_str_to_word_array.c \
		src/bsq.c \
		src/main.c	\
		src/generate_map.c

OBJ =	$(SRC:.c=.o)

CFLAGS = -Wall -Wextra -I ./include/

NAME =	bsq

all:	$(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(CFLAGS) -o $(NAME)

clean:
	rm -f $(NAME)

fclean:
	rm -f $(OBJ)

re:	fclean all

auteur:
	echo $(USER) > auteur
