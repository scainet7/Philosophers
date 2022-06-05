#include "philo.h"

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
	return (res * z);
}
/*
int ft_free(int error_num, t_parametrs *params)
{
	if (error_num == -1)
	{
		printf("ERROR_MALLOC_ARGS");
		return (-1);
	}
	else if (error_num == -2 || error_num == -3)
	{
		printf("ERROR_INIT_ARGS");
		//free(params->data);
		return (-1);
	}
	free(params);
	return (0);
}*/