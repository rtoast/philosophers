#include "philo.h"

int main(int argc, char **argv)
{
	t_init *tmp;

	tmp = NULL;
	if (argc < 4)
		ft_error("Wrong amount of arguments :(");
	tmp = init_tmp(tmp, argv);
	printf("%d\n", tmp->philo_num);
	printf("%d\n", tmp->time);
	printf("%d\n", tmp->eat);
	printf("%d\n", tmp->sleep);
}
