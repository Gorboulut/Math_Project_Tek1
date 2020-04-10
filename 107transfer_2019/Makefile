##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC = 	$(wildcard *.c)

OBJ = $(SRC:.c=.o)

NAME = navy

CFLAGS = -L -I -Wall -Wextra -g

all :	$(NAME)


$(NAME):	$(OBJ)
	$(MAKE) -C sources/lib/my
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean :
	rm -f vgcore.*
	rm -f $(OBJ)
	$(MAKE) clean -C sources/lib/my

fclean : clean
	rm -f $(NAME)
	rm -f sources/lib/my/libmy.a

re : fclean all
	$(MAKE) -C sources/lib/my

.PHONY : all clean fclean re
