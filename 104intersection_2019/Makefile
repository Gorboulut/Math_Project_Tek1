##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	$(wildcard *.c)

OBJ 	= $(SRC:.c=.o)

NAME 	= 104intersection

all :
	gcc -g $(SRC) -o $(NAME) -lm -Wall -Wextra

clean :
	rm $(NAME)
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
