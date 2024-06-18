##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	main.c					\
			movements.c				\
			ending_condition.c		\
			stock_elements.c

OBJ 	= $(SRC:.c=.o)

NAME	= 	my_sokoban

CFLAGS =	-I ./include -lncurses -Wall -Wshadow -Wextra

LDFLAGS 	=	-L ./lib/my -lmy

CC 		=	 gcc

all:	$(NAME)

./lib/my/libmy.a:
		$(MAKE) -C ./lib/my
		@cp -f ./lib/my/my.h ./include

$(NAME): ./lib/my/libmy.a $(OBJ)
		@$(CC) -g -o $(NAME) $(SRC) $(CFLAGS) $(LDFLAGS)
		@echo -e "\e[1;36m{ Binary ready !! }\e[00;37m"

clean:
		@$(RM) *~ $(OBJ)
		$(MAKE) clean -C ./lib/my
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		@$(RM) $(NAME) ./include/my.h
		$(MAKE) fclean -C ./lib/my
		@echo -e "\e[1;33m[ Binary has been deleted ]\e[00;37m"

re: fclean all
