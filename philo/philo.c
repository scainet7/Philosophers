#include "philo.h"

int main(int argc, char **argv)
{
	t_parametrs *params;
	int	flag;
	if (argc < 5 || argc > 6)
		printf(RED"ERROR_INPUT_NUM_ARGUMENTS"END);
	flag = ft_init_params(argc, argv, &params);
	if (flag < 0)
		return (0);
	return 0;
}
