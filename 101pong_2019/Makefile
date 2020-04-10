##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Compile the files
##

cc = gcc

SRC =   pong.c

OBJ =   $(SRC:.c=.o)

CFLAGS  =   -W -Wall -Wextra -Werror -I./include

NAME    =   101pong

all:    $(NAME)

$(NAME):	$(OBJ)
	cc -o $(NAME) -lm $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean  all
.PHONY:	all	clean	fclean	re
