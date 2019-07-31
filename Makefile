# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppreez <ppreez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/03 13:36:13 by ppreez            #+#    #+#              #
#    Updated: 2019/07/31 12:44:03 by ppreez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nibbler

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./includes/
DEP_PATH = ./dependencies

SRC_FILE = main.cpp Game.cpp OpenGL.cpp SDL.cpp Shader.cpp AEntity.cpp Snake.cpp Body.cpp

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

all: $(NAME) 

install: $(OBJ_PATH) setup glad cmake sdl

homebrew:
	sh -c "$$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
	reset

$(NAME): $(SRC_PATH) $(OBJ_PATH) $(INC_PATH) $(OBJ)
	$(CC) -o $@ $(OBJ) obj/glad.o $(GLFWA_INC) $(GLFW) $(SDLA_INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp glad
	$(CC) -I$(INC_PATH) $(GLFW_INC) $(GLAD_INC) $(SDL_INC)  -o $@ -c $<

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

glad: $(DEP_PATH)/glad/src/glad.c $(OBJ_PATH)
	gcc -I $(DEP_PATH)/glad/include/ -c $(DEP_PATH)/glad/src/glad.c -o ./obj/glad.o

sdl:
	mkdir $(DEP_PATH)/SDL_SRC
	mkdir $(DEP_PATH)/SDL_BUILD
	curl -O $(SDL_URL)
	tar -xf $(SDL_TAR) -C $(DEP_PATH)/SDL_SRC --strip-components 1
	$(CMAKE) -S $(DEP_PATH)/SDL_SRC  -B $(DEP_PATH)/SDL_BUILD
	make install -C $(DEP_PATH)/SDL_BUILD
	make -C $(DEP_PATH)/SDL_BUILD

cmake:
	#~/.brew/bin/brew install cmake
	~/.brew/Cellar/cmake/3.15.1/bin/cmake -S $(DEP_PATH)/glfw/ -B $(DEP_PATH)/glfw/
	make -C $(DEP_PATH)/glfw/

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm obj/glad.o

fclean: clean
	/bin/rm $(NAME)

re: fclean all

.PHONY: re fclean clean all
