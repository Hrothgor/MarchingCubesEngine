##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC =	$(wildcard src/*.cpp)		\
		$(wildcard src/*/*.cpp)		\
		$(wildcard src/*/*/*.cpp)		\

NAME = Engine_Marching_cubes

CC = g++

CPPFLAGS = -W -g3 -std=c++17 -Ofast

SFML = -DGL_GLEXT_PROTOTYPES -lOpenGL -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lm

OBJ = $(SRC:.cpp=.o)

all	: 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) $(SFML)

clean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf	$(OBJ_TESTS)

fclean: clean

re: fclean all
