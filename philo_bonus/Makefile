# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snino <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/15 15:23:59 by snino             #+#    #+#              #
#    Updated: 2022/12/05 21:19:53 by snino            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= philo_bonus

CC				:= gcc

CFLAGS			:= -g -Wall -Wextra -Werror #-fsanitize=thread

SRCS			:= 	philo_bonus.c\
					ft_philo_init_bonus.c\
					ft_philo_utils_bonus.c\

HEADER			:=	philo_bonus.h

OBJ_DIR			:=	obj_bonus

OBJ 			:=	$(addprefix $(OBJ_DIR)/, $(patsubst %.c, %.o, $(SRCS)))

.PHONY			:	all clean fclean re bonus

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					@CC $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o	:  	%.c $(HEADER)
					@mkdir -p $(OBJ_DIR)
	 				$(CC) $(CFLAGS) -c $< -o $@

clean			:
					@rm -rf $(OBJ)

fclean			:	clean
					@$(RM) $(NAME)
					@rm -rf obj_bonus

re				:	fclean all
