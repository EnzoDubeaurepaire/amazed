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
		src/init_cell_struct.c \
		src/ceil.c \
		src/fill_tab_stdin.c	\
		src/create_stwa_for_each_line.c	\
		src/parse_file.c	\
		src/init_parsing_struct.c	\
		src/free_parsing.c	\
		src/parse_cell.c	\
		src/parse_tunnel.c	\
		src/get_names_tunnel.c	\
		src/print_file.c \
		src/init_cells.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-Ofast -fno-builtin -fno-builtin-memset -flto -march=native

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
