#include "philo.h"

static void ft_init_philo(t_parametrs *params, int j, t_data *data)
{
	params->index = j + 1;
	params->count_eat = 0;
	params->time_meal = 0;
	params->data = data;

}

static int ft_init_args(int argc, char **argv, t_data **data)
{
	t_data *tmp;
	tmp = (t_data *) malloc(sizeof (t_data));
	if (!data)
		return (-1);
	tmp->philosophers = ft_atoi(argv[1]);
	tmp->nums_forks = tmp->philosophers;
	tmp->time_die = ft_atoi(argv[2]);
	tmp->time_eat = ft_atoi(argv[3]);
	tmp->time_sleep = ft_atoi(argv[4]);
	tmp->nums_eat = 0;
	if (tmp->philosophers < 1 || tmp->time_die < 1 || tmp->time_sleep < 1 ||
	tmp->time_eat < 1)
	{
		free(tmp);
		return (-1);
	}
	if (argc == 6)
	{
		tmp->nums_eat = ft_atoi(argv[5]);
		if (tmp->nums_eat < 1)
		{
			free(tmp);
			return (-1);
		}
	}
	*data = tmp;
	free(tmp);
	return (0);
}

int	ft_init_params(int argc, char **argv, t_parametrs **params)
{
	t_data *data;
	t_parametrs *tmp;
	int i;
	int j;

	i = ft_init_args(argc, argv, &data);
	if (i < 0)
		return(i);
	tmp = (t_parametrs *)malloc(sizeof(t_parametrs) * data->philosophers);
	if (!tmp)
		return (0);
	j = -1;
	while (++j < data->philosophers)
		ft_init_philo(tmp + j, j, data);
	*params = tmp;
	free(tmp);
	return (0);
}
