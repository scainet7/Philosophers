#include "philo.h"
static int ft_philo_sleep_and_thing(t_p *params, long time)
{
	long	start_sleep;

	ft_write(params, "is sleeping", time_now() - time);
	start_sleep = time_now() - time;
	while(start_sleep + params->time_sleep + time > time_now())
	{
		usleep(100);
		if(ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	ft_write(params, "is thinking", time_now() - time);
	while(params->start_eat + params->time_eat * 2 > time_now())
	{
		usleep(100);
		if(ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	return (0);
}

static int ft_philo_eat(t_p *params, long time)
{
	if (params->id % 2 == 0)
		usleep(10);
	while(params->flag == 0)
	{
		if (!pthread_mutex_lock(&params->mutex[params->fork_l]))
		{
			if (!pthread_mutex_lock(&params->mutex[params->fork_r]))
				params->flag = 1;
			else
				pthread_mutex_unlock(&params->mutex[params->fork_l]);
		}
	}
	ft_write(params, "has taken a fork", time_now() - time);
	ft_write(params, "is eating", time_now() - time);
	params->start_eat = time_now();
	while(params->time_eat + params->start_eat > time_now())
	{
		usleep(100);
		if(ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	pthread_mutex_unlock(&params->mutex[params->fork_l]);
	pthread_mutex_unlock(&params->mutex[params->fork_r]);
	params->flag = 0;
	if (!params->nums_eat)
		return (1);
	return (0);
}

void *ft_philo_process(void *link)
{
	t_p	params;
	long time;

	params = *(t_p *)link;
	pthread_mutex_unlock(&params.mutex[params.philo]);
	if(ft_check_death(&params, 0))
		return (NULL);
	if (params.philo != 1)
	{
		while (ft_check_eat(&params.nums_eat))
		{
			time = time_now();
			if (ft_philo_eat(&params, time))
				break;
			if (ft_philo_sleep_and_thing(&params, time))
				break;
			params.t_time += time_now() - time;
		}
	}
	else
		printf ("PHILO_1\n");
	//*params.otbrosil_kopita = 1;
	return (NULL);
}

int main(int argc, char **argv)
{
	t_p params;
	int death;

	params.otbrosil_kopita = &death;
	int i;
	if (ft_check_args(argc, argv))
		return (-1);
	else if (ft_init_params(argc, argv, &params))
		return (-1);
	i = -1;
//	while (++i < params.philo)
//		pthread_join(params.flow[i], NULL);
	while(!*params.otbrosil_kopita)
		usleep(params.time_die * 1000);
	free(params.mutex);
	free(params.flow);
	return 0;
}
