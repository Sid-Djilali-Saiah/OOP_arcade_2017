##
## EPITECH PROJECT, 2018
## arcade
## File description:
## created by Sid Djilali Saiah,
##

NAME	= lib_arcade_ncurses.so

CC	= g++

RM	= rm -f

SRCS	=   ../../commonSources/Sprite.cpp \
            ../../commonSources/Text.cpp \
            ./ncurses.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I../../include/

CPPFLAGS += -fPIC -W -Wall -Wextra -O3 -std=c++11

LDFLAGS =  -shared -lncurses

all: clean $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 cp lib_arcade_ncurses.so ../../lib/

clean:
	$(RM) $(OBJS)
	$(RM) ../../lib/$(NAME)

fclean: clean
	$(RM) $(NAME)

re: all

.PHONY: all clean fclean re
