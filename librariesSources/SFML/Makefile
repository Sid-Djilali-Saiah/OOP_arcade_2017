##
## EPITECH PROJECT, 2018
## arcade
## File description:
## created by Sid Djilali Saiah,
##

NAME	= lib_arcade_sfml.so

CC	= g++

RM	= rm -f

SRCS	=   ../../commonSources/Sprite.cpp \
            ../../commonSources/Text.cpp \
            ./sfml.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I../../include/

CPPFLAGS += -fPIC -W -Wall -Wextra -O3 -std=c++11

LDFLAGS =  -shared -lsfml-graphics -lsfml-window -lsfml-system

all: clean $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	 cp lib_arcade_sfml.so ../../lib/

clean:
	$(RM) $(OBJS)
	$(RM) ../../lib/$(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
