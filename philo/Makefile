NAME		= philo

SRCS		= philo.c	ft_philo_utils.c	ft_philo_init.c

HEADER		= philo.h

OBJ			= $(SRCS:%.c=%.o)

CC			= gcc

CFLAGS		= -g -Wall -Wextra -Werror -fsanitize=thread

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
