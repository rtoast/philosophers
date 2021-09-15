#include "philo.h"

void	create_flow(t_philo *philo_array)
{
	int i;
	int num;
	pthread_t *ptr;
	pthread_t	death;

	i = 0;
	num = philo_array->tmp->philo_num;
	ptr = (pthread_t *)malloc(sizeof(pthread_t) * num);
	while (i < num)
	{
		pthread_create(&(ptr[i]), NULL, cycle_of_boring_life, (void *)&(philo_array[i]));
		i++;
	}
	pthread_create(&(death), NULL, philo_die, (void *)(philo_array));
	pthread_join(death, NULL);
}

void	*philo_die(void *arg)
{
	t_philo	*philo;
	int i;

	i = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (my_get_time() >= philo[i].time_end)
		{
			printf("%4d : %d Hey I deal with death\n", my_get_time() - philo->tmp->start_time, philo->index);
			break ;
		}
		i = (i + 1) % philo->tmp->philo_num;
	}
	return(NULL);
}
