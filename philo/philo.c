#include "philo.h"
int ft_philo_eat(t_p *params)
{
	if (params->id % 2 != 0)

	pthread_mutex_lock(&params->mutex[params->fork_r]);
	pthread_mutex_lock(&params->mutex[params->fork_l]);

	pthread_mutex_unlock(&params->mutex[params->fork_r]);
	pthread_mutex_unlock(&params->mutex[params->fork_l]);

}

void *ft_philo_process(void *link)
{
	t_p	params;

	params = *(t_p *)link;
	pthread_mutex_unlock(&params.mutex[params.philo]);
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
	printf("philo %d\n", params.id);
	return (0);
}

int main(int argc, char **argv)
{
	t_p params;

	if (ft_check_args(argc, argv))
		return (-1);
	else if (ft_init_params(argc, argv, &params))
		return (-1);
	return 0;
}
