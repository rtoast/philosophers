#include "philo.h"

int main(int argc, char **argv)
{
	t_init *tmp;
	t_philo *philo_array;

	tmp = NULL;
	philo_array = NULL;
	if (argc < 4)
		ft_error("Wrong amount of arguments :(");
	tmp = init_tmp(tmp, argv);
	philo_array = create_array(tmp);
	
}
