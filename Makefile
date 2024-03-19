##
## EPITECH PROJECT, 2024
## B_PSU_200_LIL_2_1_minishell1_enzo_dubeaurepaire
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/cell_is_valid.c \
		src/cell_selection.c \
		src/check_end.c \
		src/game_loop.c \
		src/move_robots.c \
		src/free_cells.c \
		src/get_move_to_end.c \
		src/cells_len.c \
		src/check_name_cell.c	\
		src/init_cell_struct.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-Ofast -fno-builtin -flto -march=native

NAME	=	amazed

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/
	gcc -o $(NAME) $(OBJ) -Llib -lmy

tests-run:	$(OBJ)
	echo "No tests"
#	gcc -o unit_tests $(SRC) tests/test.c -lcriterion --coverage
#	./unit_tests
#	gcovr --exclude tests/

clean:
	make -C lib/ clean
	rm -f $(OBJ)

fclean:	clean
	make -C lib/ fclean
	rm -f $(NAME)

re:	fclean all
