##
## EPITECH PROJECT, 2019
## Pong
## File description:
## 101pong
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

RM	=	rm -f

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm -W -Wextra -Wall -Werror

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
