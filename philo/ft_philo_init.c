#include "philo.h"

static void ft_init_philo(t_p *params, int j)
{

	params->id = j;
	params->fork_r = j;
	printf("%d\n", j);
	if (j == (params->philo - 1))
		params->fork_l = 0;
	else
		params->fork_l = j + 1;
	pthread_create(&params->flow[j], NULL, ft_philo_process, params);
	pthread_mutex_lock(&params->mutex[params->philo]);
}

static int ft_init_args(int argc, char **argv, t_p *params)
{
	int i;

	params->philo = ft_atoi(argv[1]);
	params->nums_forks = params->philo;
	params->time_die = 1000 * ft_atoi(argv[2]);
	params->time_eat = 1000 * ft_atoi(argv[3]);
	params->time_sleep = 1000 * ft_atoi(argv[4]);
	params->nums_eat = -1;
	if (argc == 6)
		params->nums_eat = ft_atoi(argv[5]);
	i = -1;
	params->mutex = malloc(sizeof (pthread_mutex_t) * (params->philo + 2));
	if (!params->mutex)
		return (-1);
	while(++i < (params->philo + 2))
		pthread_mutex_init(&params->mutex[i], NULL);
	params->flow = malloc(sizeof (pthread_t) * (params->philo));
	if (!params->flow)
		return (-1);
	return (0);
}

int	ft_init_params(int argc, char **argv, t_p *params)
{
	int i;

	if (ft_init_args(argc, argv, params))
		return(-1);
	i = -1;
	pthread_mutex_lock(&params->mutex[params->philo]);
	while (++i < params->philo)
		ft_init_philo(params , i);
	return (0);
}
