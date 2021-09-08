#include "philo.h"

void *cycle_of_boring_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hey i %d\n", philo->index);
	return (NULL);
}
