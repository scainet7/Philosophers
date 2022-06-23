/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:22:54 by snino             #+#    #+#             */
/*   Updated: 2022/06/15 15:23:00 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_philo_sleep_and_thing(t_p *params, long time)
{
	long	start_sleep;

	ft_write(params, "is sleeping", time_now() - time);
	start_sleep = time_now() - time;
	while (start_sleep + params->time_sleep + time > time_now())
	{
		usleep(100);
		if (ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	ft_write(params, "is thinking", time_now() - time);
	while (params->start_eat + params->time_eat * 2 > time_now())
	{
		usleep(100);
		if (ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	params->flag = 0;
	return (0);
}

static int	ft_philo_eat(t_p *params, long time)
{
	sem_wait(params->sem);
	sem_wait(params->sem);
	ft_write(params, "has taken a fork", time_now() - time);
	ft_write(params, "is eating", time_now() - time);
	params->start_eat = time_now();
	while (params->time_eat + params->start_eat > time_now())
	{
		usleep (100);
		if (ft_check_death(params, time_now() - params->start_eat))
			return (1);
	}
	usleep (100);
	sem_post(params->sem);
	sem_post(params->sem);
	return (0);
}

void	ft_philo_process(t_p *params)
{
	long	time;

	if (ft_check_death(params, params->t_time))
		return ;
	if (params->philo != 1)
	{
		while (ft_check_eat(&params->nums_eat))
		{
			time = time_now();
			if (ft_philo_eat(params, time))
				break ;
			if (ft_philo_sleep_and_thing(params, time))
				break ;
			params->t_time += time_now() - time;
		}
	}
	else
		printf(GRE"0 1 philo took 1 fork\n%d %d philo died"END,
			params->time_die, params->id + 1);
	usleep(params->time_die * 1000);
	return ;
}

int	main(int argc, char **argv)
{
	t_p	params;

	if (ft_check_args(argc, argv))
		return (1);
	else if (ft_init_params(argc, argv, &params))
		return (1);
	free(params.pid);
	free(params.flow);
	sem_unlink("forks");
	sem_unlink ("printf");
	return (0);
}
