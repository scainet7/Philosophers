/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:13:15 by snino             #+#    #+#             */
/*   Updated: 2022/06/14 14:13:18 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_philo_sleep_and_thing(t_p *params, long time, int i)
{
	long	start_sleep;

	ft_write(params, "is sleeping", time_now() - time, i);
	start_sleep = time_now() - time;
	while (start_sleep + params->time_sleep + time > time_now())
	{
		usleep(100);
		if (ft_check_death(params, time_now() - params->start_eat, i))
			return (1);
	}
	ft_write(params, "is thinking", time_now() - time, i);
	while (params->start_eat + params->time_eat * 2 > time_now())
	{
		usleep(100);
		if (ft_check_death(params, time_now() - params->start_eat, i))
			return (1);
	}
	return (0);
}

static int	ft_philo_eat(t_p *params, long time, int i)
{
	pthread_mutex_lock(&params->mutex[params->fork_l]);
	pthread_mutex_lock(&params->mutex[params->fork_r]);
	ft_write(params, "has taken a fork", time_now() - time, i);
	ft_write(params, "is eating", time_now() - time, i);
	params->start_eat = time_now();
	while (params->time_eat + params->start_eat > time_now())
	{
		usleep (100);
		if (ft_check_death(params, time_now() - params->start_eat, i))
			return (1);
	}
	pthread_mutex_unlock(&params->mutex[params->fork_l]);
	pthread_mutex_unlock(&params->mutex[params->fork_r]);
	if (!params->nums_eat)
		return (1);
	return (0);
}

static int	ft_philo_live(t_p *params, int i)
{
    long	time;

	if (ft_check_death(params, 0, i))
		return (1);
	while (ft_check_eat(&params->nums_eat))
	{
        time = time_now();
        if (ft_philo_eat(params, time,  i))
            break ;
        if (ft_philo_sleep_and_thing(params, time, i))
            break ;
        params->t_time += time_now() - time;
    }
    return (0);
}

void	*ft_philo_process(void *link)
{
	t_p		params;;
    int i;

    params = *(t_p *)link;
    pthread_mutex_lock(&params.mutex[params.philo + 3]);
    i = *params.id;
    pthread_mutex_unlock(&params.mutex[params.philo]);
    pthread_mutex_unlock(&params.mutex[params.philo + 3]);
    params.fork_l = i;
    if (i == 0)
        params.fork_r = params.philo - 1;
    else if (i % 2 != 0)
    {
        params.fork_r = params.fork_l;
        params.fork_l = i - 1;
    }
    else
            params.fork_r = i - 1;
    if(ft_philo_live(&params, i))
            return (NULL);
	usleep(params.time_die * 1000);
    pthread_mutex_unlock(&params.mutex[params.philo + 2]);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_p	params;

	if (ft_check_args(argc, argv))
		return (1);
	else if (ft_init_params(argc, argv, &params))
		return (1);
    pthread_mutex_lock(&params.mutex[params.philo + 2]);
	free(params.mutex);
	free(params.flow);
	return (0);
}
