#include "philo.h"

int main(int argc, char **argv)
{
	t_init *tmp;
	t_philo *philo_array;

	tmp = NULL;
	philo_array = NULL;
	if (argc != 5 && argc != 6)
		ft_error("Wrong amount of arguments: meow :(");
	tmp = init_tmp(tmp, argv);
	philo_array = create_array(tmp);
	create_flow(philo_array);
}
