##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## for compile
##

SRC		=		src/malloc.c		\
				src/utils.c		\
				src/free.c		\
				src/calloc.c		\
				src/realloc.c		\
				src/realloc_array.c

OBJ		=		$(SRC:.c=.o)

SRC_TEST	=		tests/tests_malloc.c

OBJ_TEST	=		$(SRC_TEST:.c=.o)

NAME		=		libmy_malloc.so

NAME_TEST	=		unit_tests

CC		=		gcc

RM		=		rm -f

CPPFLAGS	=		-Wall -Wextra -fpic -I./include

CRITERION	=		-lcriterion --coverage

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -c $(CPPFLAGS) $(SRC)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) *~ *.o $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

tests_run:
	$(CC) -o $(NAME_TEST) $(SRC) $(SRC_TEST) $(CRITERION) -DTESTS -I./include/
	./$(NAME_TEST)

.PHONY: all clean fclean re tests_run
