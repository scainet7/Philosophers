#ifndef PHILO_H
# define PHILO_H

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
	int	philo;
	int	nums_forks;
	int	time_eat;
	int	time_sleep;
	int	time_die;
	int	nums_eat;
	int flag;
	pthread_mutex_t *mutex;
	pthread_t	*flow;

	int id;
	int	fork_l;
	int fork_r;

}	t_p;
//libft
int		ft_atoi(const char *str);
int		ft_isdigit(int ch);
//check
int		ft_check_args(int argc, char **argv);
int		ft_check_eat(int *eat);
//init
int		ft_init_params(int argc, char **argv, t_p *params);
//poc
void	*ft_philo_process(void *params);
long	time_now(void);
#endif //PHILO_H
