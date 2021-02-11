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

# LIBFT =			libft/libft.a

UTILS_SRCS =		utils/
ELF = 				elf/

HEADERS =			my_own_nm.h

FLAGS_OBJ = 		-c -I.
FLAGS_BIN =			-I. -o $(NAME)

SRC = 				my_own_nm.c \
					$(ELF)elf_handler.c \
					$(ELF)elf_symbols.c \
					$(UTILS_SRCS)utils.c \
					$(UTILS_SRCS)ft_itoa_hex.c \
					$(UTILS_SRCS)lists.c \
					$(UTILS_SRCS)argv_handler.c \
					$(UTILS_SRCS)sort.c \





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
