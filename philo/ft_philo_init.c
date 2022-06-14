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

int	ft_check_death(t_p *params, long time)
{
	if (time >= params->time_die)
	{
		pthread_mutex_lock(&params->mutex[params->philo + 1]);
		*params->fatum = 1;
		printf(BLU"%ld %d Philo die"END, params->t_time + time,
			params->id + 1);
		usleep(1000);
		return (1);
	}
	else
		return (0);
}

void	ft_write(t_p *params, char *str, long time)
{
	pthread_mutex_lock(&params->mutex[params->philo + 1]);
	if (!*params->fatum)
		printf(GRE"%ld %d Philo %s"END, params->t_time + time,
			params->id + 1, str);
	pthread_mutex_unlock(&params->mutex[params->philo + 1]);
}

static void	ft_init_philo(t_p *params, int j)
{
	*params->fatum = 0;
	params->t_time = 0;
	params->flag = 0;
	params->id = j;
	params->fork_l = j;
	if (j == 0)
		params->fork_r = params->philo - 1;
	else if (j == (params->philo - 1))
	{
		params->fork_r = params->fork_l;
		params->fork_l = j - 1;
	}
	else
		params->fork_r = j - 1;
	pthread_create(&params->flow[j], NULL, ft_philo_process, params);
	pthread_mutex_lock(&params->mutex[params->philo]);
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
	params->mutex = malloc(sizeof (pthread_mutex_t) * (params->philo + 2));
	if (!params->mutex)
	{
		printf(RED"ERROR_INIT_MALLOC_MUTEX"END);
		return (1);
	}
	while (++i < (params->philo + 2))
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
	i = -1;
	if (params->philo == 1)
	{
		printf(BLU"Philo 1"END);
		return (1);
	}
	else if (params->philo >= 200)
	{
		printf(BLU"ERROR_MANY_PHILO"END);
		return (1);
	}
	pthread_mutex_lock(&params->mutex[params->philo]);
	while (++i < params->philo)
	{
		ft_init_philo(params, i);
		pthread_detach(params->flow[i]);
	}
	return (0);
}
