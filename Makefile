# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:36:13 by ppreez            #+#    #+#              #
#    Updated: 2019/07/24 12:27:21 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
DEP_PATH = ./dependencies

SRC_FILE = main.cpp Game.cpp OpenGL.cpp Shader.cpp

OBJ_FILE = $(SRC_FILE:%.cpp=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror
CSTD = -std=c++17
CC = clang++ $(CSTD) $(CCFLAGS)
GLFW = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
GLFWA_INC = $(DEP_PATH)/glfw/src/libglfw3.a
GLFW_INC = -I $(DEP_PATH)/glfw/include/
GLAD_INC = -I $(DEP_PATH)/glad/include/

all: setup $(NAME) 

$(NAME): $(SRC_PATH) $(OBJ_PATH) $(INC_PATH) $(OBJ)
	$(CC) -o $@ $(OBJ) obj/glad.o $(GLFWA_INC) $(GLFW)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp glad cmake
	$(CC) -I$(INC_PATH) $(GLFW_INC) $(GLAD_INC) -o $@ -c $<

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(INC_PATH):
	mkdir $(INC_PATH)

$(SRC_PATH):
	mkdir $(SRC_PATH)

$(DEP_PATH):
	mkdir $(DEP_PATH)

setup: $(DEP_PATH)
	git submodule init
	git submodule update

glad: $(DEP_PATH)/glad/src/glad.c
	gcc -I $(DEP_PATH)/glad/include/ -c $(DEP_PATH)/glad/src/glad.c -o ./obj/glad.o

cmake:
	~/.brew/Cellar/cmake/3.15.0/bin/cmake -S $(DEP_PATH)/glfw/ -B $(DEP_PATH)/glfw/
	make -C $(DEP_PATH)/glfw/

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm obj/glad.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: re fclean clean all
