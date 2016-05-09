# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/08 14:32:27 by cdrouet           #+#    #+#              #
#    Updated: 2016/05/09 12:53:14 by cdrouet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	  img.c \
	  Mandelbrot.c \
	  Julia.c \
	  init_win.c \
	  event.c \

BIN = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror 

MINIFLAG = -lmlx -framework OpenGL -framework Appkit

LIB = -Llibft/ -lftprintf

$(NAME) :
	gcc -march=native $(FLAG) -c $(SRC);
	gcc -march=native $(FLAG) -o $(NAME) $(BIN) $(MINIFLAG) $(LIB)

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
