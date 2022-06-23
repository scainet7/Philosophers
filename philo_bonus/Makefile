# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:23:59 by snino             #+#    #+#              #
#    Updated: 2022/06/15 15:24:01 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo_bonus

SRCS		= philo_bonus.c	ft_philo_utils_bonus.c	ft_philo_init_bonus.c

HEADER		= philo_bonus.h

OBJ			= $(SRCS:%.c=%.o)

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror #-fsanitize=thread

.PHONY:		all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ)
		@CC $(CFLAGS) $(OBJ) -o $(NAME)

%.o		: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean	:
		@rm -f $(OBJ)

fclean	: clean
		@rm -f $(NAME)

re		: fclean all
