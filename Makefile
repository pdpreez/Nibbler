# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:36:13 by ppreez            #+#    #+#              #
#    Updated: 2019/07/14 13:29:52 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
GLAD_PATH = ./glad/

SRC_FILE = main.cpp Game.cpp OpenGL.cpp

OBJ_FILE = $(SRC_FILE:%.cpp=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror
CSTD = -std=c++17
CC = clang++ $(CSTD) $(CCFLAGS)
GLFW = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
GLFW_INC = ./includes/glfw/src/libglfw3.a

all: $(NAME) 

$(NAME): $(SRC_PATH) $(OBJ_PATH) $(INC_PATH) $(OBJ)
	$(CC) -o $@ $(OBJ) obj/glad.o $(GLFW_INC) $(GLFW)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) -I$(INC_PATH) -o $@ -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(INC_PATH):
	mkdir $(INC_PATH)

$(SRC_PATH):
	mkdir $(SRC_PATH)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: re fclean clean all
