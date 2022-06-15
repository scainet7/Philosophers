/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_init_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snino <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:23:36 by snino             #+#    #+#             */
/*   Updated: 2022/06/15 15:23:38 by snino            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_death(t_p *params, long time)
{
	if (time >= params->time_die)
	{
		sem_wait(params->sem_printf);
		usleep(10);
		printf(BLU"%ld %d is died"END, params->t_time + time, params->id + 1);
		return (1);
	}
	else
		return (0);
}

void	ft_write(t_p *params, char *str, long time)
{
	sem_wait(params->sem_printf);
	printf(GRE"%ld %d %s"END, params->t_time + time, params->id + 1, str);
	sem_post(params->sem_printf);
}

static void	ft_init_philo(t_p *params)
{
	int	i;

	i = -1;
	sem_unlink ("printf");
	params->sem_printf = sem_open("printf", O_CREAT, 0660, 0);
	sem_post(params->sem_printf);
	params->t_time = 0;
	params->flag = 0;
	while (++i < params->philo)
	{
		params->id = i;
		params->pid[i] = fork();
		if (!params->pid[i])
		{
			ft_philo_process(params);
			return ;
		}
	}
	waitpid(-1, &i, 0);
	i = -1;
	while (++i < params->philo)
		kill(params->pid[i], SIGTERM);
}

static int	ft_init_args(int argc, char **argv, t_p *params)
{
	params->philo = ft_atoi(argv[1]);
	params->time_die = ft_atoi(argv[2]);
	params->time_eat = ft_atoi(argv[3]);
	params->time_sleep = ft_atoi(argv[4]);
	params->nums_eat = -1;
	if (argc == 6)
		params->nums_eat = ft_atoi(argv[5]);
	params->flow = malloc(sizeof (pthread_t) * (params->philo));
	if (!params->flow)
	{
		printf(RED"ERROR_INIT_MALLOC_FLOW"END);
		return (1);
	}
	params->pid = malloc(sizeof (pid_t) * params->philo);
	if (!params->flow)
	{
		printf(RED"ERROR_INIT_MALLOC_PID"END);
		return (1);
	}
	sem_unlink("forks");
	params->sem = sem_open("forks", O_CREAT, 0660, params->philo);
	return (0);
}

int	ft_init_params(int argc, char **argv, t_p *params)
{
	if (ft_init_args(argc, argv, params))
		return (1);
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
	ft_init_philo(params);
	return (0);
}
