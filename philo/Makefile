# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:42:20 by snino             #+#    #+#              #
#    Updated: 2022/06/14 15:42:25 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS		= philo.c	ft_philo_utils.c	ft_philo_init.c

HEADER		= philo.h

OBJ			= $(SRCS:%.c=%.o)

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror #-fsanitize=thread

.PHONY:		all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		@CC $(CFLAGS) $(OBJ) -o $(NAME)

%.o		: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@ -I

clean	:
		@rm -f $(OBJ)

fclean	: clean
		@rm -f $(NAME)

re		: fclean all
