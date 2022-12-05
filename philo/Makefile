# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/14 15:42:20 by snino             #+#    #+#              #
#    Updated: 2022/12/05 21:13:58 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo

CC					:=	gcc

CFLAGS				:=	-g -Wall -Wextra -Werror #-fsanitize=thread

SRCS				:=	philo.c\
						ft_philo_init.c\
						ft_philo_utils.c\

HEADER				:=	philo.h

OBJ_DIR				:=	obj

OBJ 				:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

.PHONY				:	all clean fclean re

all					:	$(NAME)

$(NAME)				:	$(HEADER) $(OBJ)
						$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o		:  	%.c $(HEADER)
						@mkdir -p $(OBJ_DIR)
	 					$(CC) $(CFLAGS) -c $< -o $@

clean				:
						@rm -rf $(OBJ)

fclean				:	clean
						@$(RM) $(NAME)
						@rm -rf obj

re					:	fclean all
