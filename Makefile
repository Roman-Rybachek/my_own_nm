# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 19:36:23 by jeldora           #+#    #+#              #
#    Updated: 2020/09/03 01:58:26 by jeldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				my_own_nm

HEADERS =			my_own_nm.h

FLAGS_OBJ = 		-c -Wall -Wextra -Werror -I.
FLAGS_BIN =			 -Wall -Wextra -Werror -o $(NAME)

SRC = 				my_own_nm.c \
					utils.c \
					elf_handler.c




OBJ =			$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	gcc $(OBJ) $(FLAGS_BIN)

%.o: %.c
	gcc $(FLAGS_OBJ) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
