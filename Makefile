##
## EPITECH PROJECT, 2021
## B-PSU-200-PAR-2-1-bsmysokoban-ines.maaroufi
## File description:
## Makefile
##

SRC	=	./lib/lib_functions.c\
		./lib/lib_functions2.c\
		./sources/handle_map.c\
		./sources/move_box.c\
		./sources/move_player.c\
		./sources/loop_game.c\
		./sources/check_functions.c\
		./sources/get_functions.c\
		main.c

TESTS_SRC	=	./tests/test_project.c\
				./lib/lib_functions.c\
				./lib/lib_functions2.c\
				./sources/handle_map.c\
				./sources/move_box.c\
				./sources/move_player.c\
				./sources/check_functions.c\
				./sources/get_functions.c\

OBJ_SRC	=	$(TEST_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

NAME_TEST	=	unit_tests

TEST_FLAGS	=	--coverage -lncurses -lcriterion

CFLAGS	=	-Wextra -Wall -g3 -I./includes

all:	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS)	-lncurses

tests_clean:
	rm -f *.gcno*
	rm -f *.gcda*

clean:
	rm -f $(OBJ)

tests_fclean: tests_clean
	rm -f $(NAME_TEST)

fclean:	clean tests_fclean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o unit_tests $(TESTS_SRC) $(TEST_FLAGS) $(CFLAGS)
	./unit_tests

tests_re: tests_fclean tests_run

.PHONY:	all tests_run clean fclean re