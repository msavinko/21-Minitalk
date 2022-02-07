# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marlean <marlean@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 16:17:56 by marlean           #+#    #+#              #
#    Updated: 2021/11/26 15:42:36 by marlean          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRCS	=	ft_printf.c ft_utils_printf.c ft_hex.c ft_nbr.c ft_printf_bonus.c 
HEADER	=	ft_printf.h
OBJ		=	$(patsubst %.c,%.o,$(SRCS))
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
RM		= 	rm -f

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
	ar rcs $(NAME) $?

%.o		:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

bonus	:	all

clean	:
	$(RM) $(OBJ) $(OBJ_B)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all