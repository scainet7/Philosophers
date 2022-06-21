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

void	ft_write(t_p *params, char *str, long time)
{
	pthread_mutex_lock(&params->mutex[params->philo + 1]);
	if (!params->fatum[params->id])
		printf(GRE"%ld %d %s"END, params->t_time + time,
			params->id + 1, str);
	pthread_mutex_unlock(&params->mutex[params->philo + 1]);
}

void	ft_init_philo(t_p *params, int j)
{
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

static int ft_init_eat_and_death(int argc, char **argv, t_p *params)
{
    int i;

    params->nums_eat = malloc(sizeof (int) * params->philo);
    if (!params->nums_eat)
        return (1);
    params->fatum = malloc(sizeof (int) * params->philo);
    if (!params->fatum)
        return (1);
    i = -1;
    while (++i < params->philo)
    {
        params->nums_eat[i] = -1;
        params->fatum[i] = 0;
    }
    i = -1;
    if (argc == 6)
        while (++i < params->philo)
            params->nums_eat[i] = ft_atoi(argv[5]);
    return (0);
}

static int	ft_init_args(int argc, char **argv, t_p *params)
{
	int	i;

	params->philo = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
    if (ft_init_eat_and_death(argc, argv, params))
            return (1);
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
	i = -1;
	if (params->philo == 1)
	{
		printf(BLU"Philo 1"END);
		return (1);
	}
	else if (params->philo > 200)
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
