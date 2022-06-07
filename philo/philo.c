#include "philo.h"
int ft_philo_eat(t_p *params)
{
//	if (params->id % 2 != 0)
//		usleep(2);
	while(params->flag == 0)
	{
		if (!pthread_mutex_lock(&params->mutex[params->fork_l]))
		{
			if (!pthread_mutex_lock(&params->mutex[params->fork_r]))
			{
				printf("Philo %d Vzyl vilki\n", params->id);
				params->flag = 1;
			}
			else
				pthread_mutex_unlock(&params->mutex[params->fork_l]);
		}
		else
			usleep(2);
	}
	pthread_mutex_unlock(&params->mutex[params->fork_l]);
	pthread_mutex_unlock(&params->mutex[params->fork_r]);
	params->flag = 0;
	printf("philo %d eda %d\n", params->id, params->nums_eat);
	if (!params->nums_eat)
		return (1);
	return (0);
}

void *ft_philo_process(void *link)
{
	t_p	params;

	params = *(t_p *)link;
	pthread_mutex_unlock(&params.mutex[params.philo]);
	printf("philo %d\n", params.id);
	printf("fork_l %d\n", params.fork_l);
	printf("fork_r %d\n", params.fork_r);
	printf("eda %d\n", params.nums_eat);
	if (params.philo != 1)
	{
		while (ft_check_eat(&params.nums_eat))
		{
			if (ft_philo_eat(&params))
				break;
		}
	}
	else
		printf ("PHILO_1");
	return (NULL);
}

int main(int argc, char **argv)
{
	t_p params;

	if (ft_check_args(argc, argv))
		return (-1);
	else if (ft_init_params(argc, argv, &params))
		return (-1);
	free(params.mutex);
	free(params.flow);
	return 0;
}
