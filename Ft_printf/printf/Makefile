# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbourre <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:31:14 by cbourre           #+#    #+#              #
#    Updated: 2022/04/19 10:56:25 by cbourre          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

SRCS = 		ft_printf.c \
			ft_print_char.c \
			ft_print_ptr.c \
			ft_print_str.c \
			ft_print_dec.c \
			ft_print_dec_uns.c \
			ft_print_hexa.c

HEADERS =	libftprintf.h

CC =		gcc -g

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -f

CLIB =		ar -rcs

OBJ =		$(SRCS:.c=.o)

all: $(NAME)
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	$(CLIB) $(NAME) $(OBJ)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
