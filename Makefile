# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 14:32:27 by cdrouet           #+#    #+#              #
#    Updated: 2016/04/20 13:26:25 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  img.c \
	  Mandelbrot.c \

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror 

MINIFLAG = -lmlx -framework OpenGL -framework Appkit

LIB = -Llibft/ -lftprintf

$(NAME) :
	gcc $(FLAG) -c $(SRC);
	gcc $(FLAG) -o $(NAME) $(BIN) $(MINIFLAG) $(LIB)

all : $(NAME)

libftfclean :
	make -C libft/ fclean

libftclean :
	make -C libft/ clean

clean : 
	rm -f $(BIN)

fclean : clean 
	rm -f $(NAME)

re : fclean all
