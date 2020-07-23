# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/06 12:54:20 by ndreadno          #+#    #+#              #
#    Updated: 2020/07/09 23:54:01 by ndreadno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = header/ft_printf.h

OBJ =  src/printf_atoi.o src/printf_utils.o src/ft_printf.o src/print_flags.o\
src/print_nbr.o src/print_hex_pointer.o src/print_str.o src/print.o src/check_flags.o
	
SRC = $(OBJ:.o=.c)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
$(NAME):$(OBJ) $(HEADER)
	ar rc $(NAME) $?
	ranlib $(NAME)
%.o:%.c
	gcc -I ../$(HEADER) -c $< -o $@
clean:
	/bin/rm -f $(OBJ)
fclean:clean
	/bin/rm -f $(NAME)
re:fclean all