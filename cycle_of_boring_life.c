#include "philo.h"

void *cycle_of_boring_life(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		eating(philo);
		if (philo->num_eat == philo->tmp->amount_eat)
			break ;
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
	print(1, my_get_time() - philo->tmp->start_time, philo->index, &(philo->tmp->message));
	pthread_mutex_lock(philo->left);
	print(1, my_get_time() - philo->tmp->start_time, philo->index, &(philo->tmp->message));
	(philo->num_eat)++;
	print(2, my_get_time() - philo->tmp->start_time, philo->index, &(philo->tmp->message));
	philo->time_end = my_get_time() + philo->tmp->time;
	my_sleep(philo->tmp->eat);
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
}

void	sleeping(t_philo *philo)
{
	print(3, my_get_time() - philo->tmp->start_time, philo->index, &(philo->tmp->message));
	my_sleep(philo->tmp->sleep);
}

void	thinking(t_philo *philo)
{
	print(4, my_get_time() - philo->tmp->start_time, philo->index, &(philo->tmp->message));
}