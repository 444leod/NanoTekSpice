##
## EPITECH PROJECT, 2024
## NanoTekSpice
## File description:
## Makefile
##

NAME		=	nanotekspice

SRC_MAIN =  ./src/main.cpp \
			./src/NanoTekSpice.cpp \
			./src/Parser.cpp \
			./src/Shell.cpp \
			./src/IComponentFactory.cpp \
			./src/AComponent.cpp \
			./src/Pin.cpp

SRC_COMPONENTS = ./src/GatesComponents/My4011.cpp \
	./src/GatesComponents/My4030.cpp \
	./src/GatesComponents/AGatesComponent.cpp \
	./src/GatesComponents/My4001.cpp \
	./src/GatesComponents/My4071.cpp \
	./src/GatesComponents/My4081.cpp \
	./src/GatesComponents/My4069.cpp \
	./src/SpecialComponents/True.cpp \
	./src/SpecialComponents/False.cpp \
	./src/SpecialComponents/Output.cpp \
	./src/SpecialComponents/ASpecialComponent.cpp \
	./src/SpecialComponents/Clock.cpp \
	./src/SpecialComponents/Input.cpp \
	./src/ElementatyComponents/And.cpp \
	./src/ElementatyComponents/Xor.cpp \
	./src/ElementatyComponents/Not.cpp \
	./src/ElementatyComponents/Or.cpp \
	./src/ElementatyComponents/ElementaryComponent.cpp \
	./src/AdvancedComponents/Logger.cpp \
	./src/AdvancedComponents/My4008.cpp \
	./src/AdvancedComponents/My4013.cpp \
	./src/AdvancedComponents/My4512.cpp	\

SRC			=	${SRC_MAIN} ${SRC_COMPONENTS} ${SRC_COMMANDS}

OBJ			=	$(SRC:.cpp=.o)

TESTS_NAME	=	unit_tests

PYTHON_TESTER = ./tests/tester.py

TESTS_SRC	=	$(filter-out ./src/main.cpp, $(SRC)) tests/parsing.cpp

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
	$(PYTHON_TESTER)


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
