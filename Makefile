# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:35:50 by malaoui           #+#    #+#              #
#    Updated: 2019/11/13 22:48:40 by malaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_base.c\
	ft_flag_minus.c\
	ft_flag_zero.c\
	ft_no_flag.c

LIB = libft.a

FLAGS = -Wall -Werror -Wextra -c

GC = gcc

all: $(NAME)

$(NAME):
	$(GC) $(FLAGS) $(SRC)
	ar x $(LIB)
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
