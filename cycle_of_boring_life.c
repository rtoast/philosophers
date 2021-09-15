#include "philo.h"

void *cycle_of_boring_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	if ((philo->index % 2) == 1)
		usleep(200);
	pthread_mutex_lock(philo->right);
	printf("%4d : %d Hey I deal with right fork\n", my_get_time() - philo->tmp->start_time, philo->index);
	pthread_mutex_lock(philo->left);
	printf("%4d : %d Hey I deal with left fork\n", my_get_time() - philo->tmp->start_time, philo->index);
	printf("%4d : %d Hey I deal with meal\n", my_get_time() - philo->tmp->start_time, philo->index);
	philo->time_end = my_get_time() + philo->tmp->time;
	my_sleep(philo->tmp->eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	sleeping(t_philo *philo)
{
	printf("%4d : %d Hey I deal with dream\n", my_get_time() - philo->tmp->start_time, philo->index);
	my_sleep(philo->tmp->sleep);
}

void	thinking(t_philo *philo)
{
	printf("%4d : %d Hey I deal with my brain\n", my_get_time() - philo->tmp->start_time, philo->index);
}