#include "philo.h"

void	create_flow(t_philo *philo_array)
{
	int i;
	int num;
	pthread_t *ptr;

	i = 0;
	num = philo_array->tmp->philo_num;
	ptr = (pthread_t *)malloc(sizeof(pthread_t) * num);
	ptr = NULL;
	while (i < num)
	{
		pthread_create(&(ptr[i]), NULL, cycle_of_boring_life, (void *)&(philo_array[i]));
		i++;
	}
}