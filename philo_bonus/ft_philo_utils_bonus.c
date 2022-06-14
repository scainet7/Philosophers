#include "philo_bonus.h"

int	ft_check_eat(int *eat)
{
	if (*eat == -1)
		return (1);
	else if (*eat == 0)
		return (0);
	else
		return (--(*eat) + 1);
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
			if (!ft_isdigit(argv[i][j++]) || (ft_atoi(argv[i]) <= 0 &&
				argv[i][0] == '0'))
			{
				printf(RED"ERROR\nPLEASE_CHECK_ARGUMENTS"END);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	res;
	long int	old;
	int			z;
	int			i;

	if (!str)
		return (0);
	z = 1;
	i = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		z = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		old = res;
		res = res * 10 + (str[i++] - 48);
		if ((old < 0 && res > 0) || (old > 0 && res < 0))
			return ((z == 1) * -1);
	}
	return ((int)res * z);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
