#include "philo.h"

void ft_check_stop(t_p *params)
{
    int n_eat;
    int i;

    i = -1;
    n_eat = 0;
    usleep(1);
    pthread_mutex_lock(&params->mutex[params->philo + 1]);
    while (n_eat != params->philo && params->fatum[++i] != 1)
    {

        if (params->nums_eat[i] == 0)
            n_eat++;
        else if (i >= params->philo - 1)
        {
            i = -1;
            if (n_eat == params->philo)
                break;
            else
            {
                pthread_mutex_unlock(&params->mutex[params->philo + 1]);
                n_eat = 0;
            }
        }
        pthread_mutex_lock(&params->mutex[params->philo + 1]);
    }
}

int	ft_check_death(t_p *params, long time)
{
    if (time >= params->time_die)
    {
        pthread_mutex_lock(&params->mutex[params->philo + 1]);
        params->fatum[params->id] = 1;
        printf(BLU"%ld %d is died"END, params->t_time + time,
                params->id + 1);
        pthread_mutex_unlock(&params->mutex[params->philo + 1]);
        usleep(1000);
        return (1);
    }
    else
        return (0);
}

int	ft_check_eat(t_p *params)
{
    pthread_mutex_lock(&params->mutex[params->philo + 1]);
    if (params->nums_eat[params->id] == -1)
    {
        pthread_mutex_unlock(&params->mutex[params->philo + 1]);
        return (1);
    }
    else if (params->nums_eat[params->id] == 0)
    {
        pthread_mutex_unlock(&params->mutex[params->philo + 1]);
        return (0);
    }
    else
    {
        pthread_mutex_unlock(&params->mutex[params->philo + 1]);
        return (--(params->nums_eat[params->id]) + 1);
    }
}

int	ft_check_args(int argc, char **argv)
{
    int	i;
    int	j;

    if (argc < 5 || argc > 6)
    {
        printf(RED"ERROR\nPLEASE_CHECK_ARGUMENTS"END);
        return (1);
    }
    i = 0;
    while (++i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j++]) || (ft_atoi(argv[i]) <= 0 ||
                                              argv[i][0] == '0'))
            {
                printf(RED"ERROR\nPLEASE_CHECK_ARGUMENTS"END);
                return (1);
            }
        }
    }
    return (0);
}