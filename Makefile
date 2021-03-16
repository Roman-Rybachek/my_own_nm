# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeldora <jeldora@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/07 19:36:23 by jeldora           #+#    #+#              #
#    Updated: 2021/03/15 05:26:48 by jeldora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 				my_own_nm

# LIBFT =			libft/libft.a

UTILS_DIR =			utils
ELF_DIR = 			elf_srcs
PE_DIR =			pe_srcs

HEADERS =			my_own_nm.h \
					shared.h \
					$(ELF_DIR)/elf_header.h \
					system_headers/pe_sys.h \
					system_headers/elf_sys.h

FLAGS = 			-I. -I$(ELF_DIR) -I$(PE_DIR) -I$(UTILS_DIR) -Isystem_headers

ELF_HANDLER_SRC =	$(ELF_DIR)/elf_handler.c \
					$(ELF_DIR)/elf_symbols.c \
					$(ELF_DIR)/elf_utils.c

UTILS_SRCS = 		$(UTILS_DIR)/utils.c \
             		$(UTILS_DIR)/ft_itoa_hex.c \
             		$(UTILS_DIR)/lists.c \
             		$(UTILS_DIR)/argv_handler.c \
             		$(UTILS_DIR)/sort.c \
             		$(UTILS_DIR)/utils2.c

PE_HANDLER_SRCS =	$(PE_DIR)/pe_handler.c \
					$(PE_DIR)/pe_utils.c



SRC = 				$(UTILS_SRCS) \
					$(ELF_HANDLER_SRC) \
					$(PE_HANDLER_SRCS) \
					my_own_nm.c
					# $(UTILS_SRCS)/arch_system_v.c

OBJ =			$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	gcc $(OBJ) $(FLAGS) -o $(NAME)


%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
