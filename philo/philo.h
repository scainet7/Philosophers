/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:13:23 by snino             #+#    #+#             */
/*   Updated: 2022/06/14 14:13:27 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define BLU "\033[34m"
# define GRE "\033[32m"
# define RED "\033[31m"
# define END "\033[0m\n"
# include <unistd.h> // usleep, write
# include <stdio.h> // printf
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <sys/time.h> // gettimeofday
# include <pthread.h> //pthread_create

typedef struct s_parameters
{
	int				philo;
	int				time_eat;
	int				time_sleep;
	int				time_die;
	int				nums_eat;
	pthread_mutex_t	*mutex;
	pthread_t		*flow;

	int				*id;
//	int				fork_l;
//	int				fork_r;
	long		t_time;
	long		start_eat;

}	t_p;
//libft
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
//check
int		ft_check_args(int argc, char **argv);
int		ft_check_eat(int *eat);
int		ft_check_death(t_p *params, long time, int i);
//init
int		ft_init_params(int argc, char **argv, t_p *params);
//poc
void	*ft_philo_process(void *link);
void	ft_write(t_p *params, char *str, long time, int i);
long	time_now(void);
#endif //PHILO_H
