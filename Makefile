##
## EPITECH PROJECT, 2018
## arcade
## File description:
## created by Sid Djilali Saiah,
##

NAME	= arcade

CC = g++

RM	= rm -f

SRC	= src/Arcade.cpp \
        src/main.cpp \
        ./commonSources/Sprite.cpp \
        ./src/Score.cpp \
        ./src/Menu.cpp \
        ./commonSources/Text.cpp

OBJS	= $(SRC:.cpp=.o)

LIBSRC  = librariesSources/
GAMESSRC  = gamesSources/


CPPFLAGS = -I./include/

CPPFLAGS += -W -Wall -Wextra -rdynamic -std=c++11

LDFLAGS = -ldl

all: core games graphicals

core:  $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

games:
	mkdir -p games
	make -C $(GAMESSRC)

graphicals:
	mkdir -p lib
	make -C $(LIBSRC)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBSRC)
	make clean -C $(GAMESSRC)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBSRC)
	make fclean -C $(GAMESSRC)

re: fclean all

.PHONY: all clean fclean re core games graphicals

