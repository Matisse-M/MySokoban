##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile to compil the -lmy
##

SRC		=	concat_params.c				\
			convert_base.c 				\
			my_compute_power_rec.c 		\
			my_compute_square_root.c 	\
			my_find_prime_sup.c 		\
			my_getnbr.c 				\
			my_intlen.c 				\
			my_is_prime.c 				\
			my_isneg.c 					\
			my_itoa.c      				\
			my_put_nbr.c 				\
			my_put_unsigned.c 			\
			my_putchar.c 				\
			my_putstr.c 				\
			my_revstr.c 				\
			my_show_word_array.c 		\
			my_sort_int_array.c 		\
			my_str_isalpha.c 			\
			my_str_islower.c 			\
			my_str_isnum.c 				\
			my_str_isprintable.c 		\
			my_str_isupper.c 			\
			my_str_to_word_array.c 		\
			my_strcat.c 				\
			my_strcmp.c 				\
			my_strcpy.c 				\
			my_strdup.c 				\
			my_strlen.c 				\
			my_strlowcase.c 			\
			my_strncat.c 				\
			my_strncmp.c 				\
			my_strncpy.c 				\
			my_strndup.c 				\
			my_strstr.c 				\
			my_strupcase.c 				\
			my_swap.c 					\
			my_tablen.c 				\
			my_unsignedlen.c

OBJ 	= 	$(SRC:.c=.o)

NAME	= 	libmy.a

CFLAGS 	=	-Wall -Wshadow -Wextra

CC 		= 	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		@$(AR) rc $(NAME) $(OBJ)
		@echo -e "\e[1;36m{ libmy.a ready and my.h duplicated !! }\e[00;37m"

clean:
		@rm -f $(OBJ)
		@rm -f *~
		@echo -e "\e[1;33m[ Useless files have been deleted ]\e[00;37m"

fclean: clean
		@$(RM) $(NAME)
		@echo -e "\e[1;33m[ libmy.a has been deleted ]\e[00;37m"

re: fclean all
