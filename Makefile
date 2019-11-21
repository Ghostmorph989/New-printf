# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malaoui <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 17:35:50 by malaoui           #+#    #+#              #
#    Updated: 2019/11/16 22:40:14 by malaoui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c\
	ft_base.c\
	ft_manage_c.c\
	ft_manage_s.c\
	ft_manage_s_extended.c\
	ft_manage_p.c\
	ft_manage_di.c\
	ft_manage_diutils.c\
	ft_manage_x.c\
	ft_manage_x_extended.c\
	ft_manage_xx.c\
	ft_manage_xxutils.c\
	ft_manage_u.c\
	ft_manage_uutils.c\
	ft_flag_minus.c\
	ft_flag_zero.c\
	ft_no_flag.c\
	ft_manage_simple.c

LIB = libft.a

FLAGS =  -c

GC = gcc -Wall -Werror -Wextra

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
