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

typedef struct s_data
{
	int	philosophers;
	int	nums_forks;
	int	time_eat;
	int	time_sleep;
	int	time_die;
	int	nums_eat;
}	t_data;

typedef struct s_parameters
{
	//int fork_l;
	//int fotk_r;
	//pthread_t philo;
	int	index;
	int count_eat;
	long long int time_meal;
	t_data *data;

}	t_parametrs;

int	ft_atoi(const char *str);
int ft_free(int error_num, t_parametrs *params);
int	ft_init_params(int argc, char **argv, t_parametrs **params);
#endif //PHILO_H
