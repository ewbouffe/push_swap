# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ewbouffe <ewbouffe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/09 13:08:48 by ewbouffe          #+#    #+#              #
#    Updated: 2025/02/28 11:19:36 by ewbouffe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = printf_lib.c printf_main.c printf_mem_utils.c printf_convert_utils.c

OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

HEADER = ft_printf.h
all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)
%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o

fclean : 
	make clean
	rm -rf $(NAME)

re : 
	make fclean
	make all
	
test :
	cc $(SRCS) main.c -g3 && valgrind ./a.out
norme :
	norminette $(SRCS) $(HEADER)
.PHONY : all clean fclean re