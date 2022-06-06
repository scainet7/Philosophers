#include "philo.h"

void *ft_philo_process(void *link)
{
	t_p	params;

	params = *(t_p *)link;
	pthread_mutex_unlock(&params.mutex[params.philo]);
	printf("philo %d\n", params.id);
	return (0);
}

int main(int argc, char **argv)
{
	t_p params;

	if (ft_check_args(argc, argv))
		return (-1);
	else if (ft_init_params(argc, argv, &params))
		return (-1);
	return 0;
}
