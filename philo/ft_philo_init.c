/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:14:02 by snino             #+#    #+#             */
/*   Updated: 2022/06/14 14:14:08 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_p *params, long time, int i)
{
	if (time >= params->time_die)
	{
		pthread_mutex_lock(&params->mutex[params->philo + 1]);
		printf(BLU"%ld %d is died"END, params->t_time + time,
			i + 1);
		usleep(1000);
		return (1);
	}
	else
		return (0);
}

void	ft_write(t_p *params, char *str, long time, int i)
{
	pthread_mutex_lock(&params->mutex[params->philo + 1]);
	printf(GRE"%ld %d %s"END, params->t_time + time, i + 1, str);
	pthread_mutex_unlock(&params->mutex[params->philo + 1]);
}

static int	ft_init_args(int argc, char **argv, t_p *params)
{
	int	i;

	params->philo = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	params->nums_eat = -1;
	if (argc == 6)
		params->nums_eat = ft_atoi(argv[5]);
	i = -1;
	params->mutex = malloc(sizeof (pthread_mutex_t) * (params->philo + 4));
	if (!params->mutex)
	{
		printf(RED"ERROR_INIT_MALLOC_MUTEX"END);
		return (1);
	}
	while (++i < (params->philo + 4))
		pthread_mutex_init(&params->mutex[i], NULL);
	params->flow = malloc(sizeof (pthread_t) * (params->philo));
	if (!params->flow)
	{
		printf(RED"ERROR_INIT_MALLOC_FLOW"END);
		return (1);
	}
	return (0);
}

int	ft_init_params(int argc, char **argv, t_p *params)
{
	int	i;

	if (ft_init_args(argc, argv, params))
		return (1);
	params->id = malloc(sizeof (int *));
	if (!params->id)
	{
		printf(RED"ERROR_INIT_MALLOC_ID"END);
		return (1);
	}
	pthread_mutex_lock(&params->mutex[params->philo + 2]);
	i = -1;
	while (++i < params->philo)
	{
		pthread_mutex_lock(&params->mutex[params->philo]);
		pthread_mutex_lock(&params->mutex[params->philo + 3]);
		*params->id = i;
		pthread_mutex_unlock(&params->mutex[params->philo + 3]);
		pthread_create(&params->flow[i], NULL, ft_philo_process, params);
		pthread_detach(params->flow[i]);
	}
	return (0);
}
