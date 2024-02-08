##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

NAME		=	nanotekspice

SRC			=	src/main.cpp							\
				src/NanoTekSpice.cpp					\

OBJ			=	$(SRC:.cpp=.o)

TESTS_NAME	=	unit_tests

TESTS_SRC	=	$(filter-out src/main.cpp, $(SRC)) tests/parsing.cpp

TESTS_OBJ   =   $(TESTS_SRC:.cpp=.o)

CC			=	g++

CPPFLAGS	=	-std=c++20 -W -Wall -Wextra -Wpedantic -I./include/

DEBUGFLAGS = -g

TESTS_FLAGS	=	-lcriterion --coverage -fprofile-arcs -ftest-coverage



all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) $(CPPFLAGS) -o $(NAME)

debug:
	$(CC) $(SRC) $(CPPFLAGS) $(DEBUGFLAGS) -o $(NAME)

run:	all
	./$(NAME) -d $(D)

tests_run:	fclean $(TESTS_OBJ)
	$(CC) $(TESTS_OBJ) $(CPPFLAGS) -o $(TESTS_NAME)
	./$(TESTS_NAME)

$(TESTS_NAME):
	@$(CC) -o $(TESTS_NAME) $(TESTS_SRC) $(CPPFLAGS) $(TESTS_FLAGS)

cov:
	gcovr --exclude tests -u

covb:
	gcovr --exclude tests -ub

clean:
	rm -f $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)
	rm -f $(TESTS_NAME)

re:	fclean all
