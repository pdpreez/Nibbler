# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:36:13 by ppreez            #+#    #+#              #
#    Updated: 2019/08/06 11:29:21 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
SO_PATH = ./shared/
DEP_PATH = ./dependencies

SRC_FILE = main.cpp Game.cpp AEntity.cpp Snake.cpp Body.cpp Fruit.cpp

OBJ_FILE = $(SRC_FILE:%.cpp=%.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

CCFLAGS = -Wall -Wextra -Werror
CSTD = -std=c++17
CC = clang++ $(CSTD) $(CCFLAGS)
CMAKE = ~/.brew/Cellar/cmake/3.15.1/bin/cmake

GLFW = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
GLFWA_INC = $(DEP_PATH)/glfw/src/libglfw3.a
GLFW_INC = -I $(DEP_PATH)/glfw/include/
GLAD_INC = -I $(DEP_PATH)/glad/include/

SDL_TAR = SDL2-2.0.10.tar.gz
SDL_URL = https://www.libsdl.org/release/$(SDL_TAR)
SDL_INC = -I ~/.brew/include/SDL2/
SDLA_INC = $(DEP_PATH)/SDL_BUILD/libSDL2.a $(DEP_PATH)/SDL_BUILD/libSDL2main.a -framework AudioToolbox -framework CoreVideo -framework Carbon -framework ForceFeedback -framework IOKit -framework Cocoa -framework CoreAudio -liconv -lm  -Wl,-current_version,10.0.0 -Wl,-compatibility_version,1.0.0 -Wl,-undefined,error
SDL_H_PATH = ~/.brew/include/SDL2/

SFML_INC = -I ./msfml/include
SFMLA_INC = -F msfml/Frameworks -Wl,-rpath,$(PWD)/msfml/Frameworks -framework sfml-graphics -framework sfml-audio -framework sfml-network -framework sfml-window -framework sfml-system

all: $(NAME) 

install: $(OBJ_PATH) setup glad_install cmake_install sdl_install

homebrew:
	sh -c "$$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	reset

$(NAME): $(SRC_PATH) $(OBJ_PATH) $(INC_PATH) $(OBJ) $(SO_PATH) shared_obj
	$(CC) -o $@ $(OBJ)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) -I$(INC_PATH) -o $@ -c $<

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(INC_PATH):
	mkdir -p $(INC_PATH)

$(SRC_PATH):
	mkdir -p $(SRC_PATH)

$(DEP_PATH):
	mkdir -p $(DEP_PATH)

$(SO_PATH):
	mkdir -p $(SO_PATH)

setup: $(DEP_PATH)
	git submodule init
	git submodule update

shared_obj: sdl opengl sfml

sdl:
	$(CC) -c $(SRC_PATH)sdl.cpp -o $(OBJ_PATH)sdl.o -I $(SDL_H_PATH) -I $(INC_PATH)
	$(CC) -shared $(OBJ_PATH)sdl.o -o $(SO_PATH)SDL.so $(SDLA_INC)

opengl: glad_install
	$(CC) -c $(SRC_PATH)OpenGL.cpp -o $(OBJ_PATH)OpenGL.o -I $(INC_PATH) $(GLAD_INC) $(GLFW_INC)
	$(CC) -c $(SRC_PATH)Shader.cpp -o $(OBJ_PATH)Shader.o -I $(INC_PATH) $(GLAD_INC) $(GLFW_INC)
	$(CC) -shared $(OBJ_PATH)OpenGL.o $(OBJ_PATH)Shader.o $(OBJ_PATH)glad.o -o $(SO_PATH)OpenGL.so $(GLFWA_INC) $(GLFW)

sfml: #sfml_install
	$(CC) -c $(SRC_PATH)SFML.cpp -o $(OBJ_PATH)sfml.o -I $(INC_PATH) $(SFML_INC)
	$(CC) -shared $(OBJ_PATH)sfml.o -o $(SO_PATH)SFML.so $(SFMLA_INC)

glad_install: $(DEP_PATH)/glad/src/glad.c $(OBJ_PATH)
	gcc -I $(DEP_PATH)/glad/include/ -c $(DEP_PATH)/glad/src/glad.c -o ./obj/glad.o

sdl_install:
	mkdir -p $(DEP_PATH)/SDL_SRC
	mkdir -p $(DEP_PATH)/SDL_BUILD
	curl -O $(SDL_URL)
	tar -xf $(SDL_TAR) -C $(DEP_PATH)/SDL_SRC --strip-components 1
	$(CMAKE) -S $(DEP_PATH)/SDL_SRC  -B $(DEP_PATH)/SDL_BUILD
	make install -C $(DEP_PATH)/SDL_BUILD
	make -C $(DEP_PATH)/SDL_BUILD

sfml_install:
	mkdir -p $(DEP_PATH)/SFML_BUILD
	$(CMAKE) -S $(DEP_PATH)/SFML -B $(DEP_PATH)/SFML_BUILD
	#make install -C $(DEP_PATH)/SFML_BUILD
	make -C $(DEP_PATH)/SFML_BUILD

cmake_install:
	#~/.brew/bin/brew install cmake
	~/.brew/Cellar/cmake/3.15.1/bin/cmake -S $(DEP_PATH)/glfw/ -B $(DEP_PATH)/glfw/
	make -C $(DEP_PATH)/glfw/

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf obj/glad.o
	/bin/rm -rf $(SO_PATH)%.so

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: re fclean clean all
