/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:34:25 by rtoast            #+#    #+#             */
/*   Updated: 2021/09/15 23:35:48 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_flow(t_philo *philo_array)
{
	int			i;
	int			num;
	pthread_t	*ptr;
	pthread_t	death;

	i = 0;
	num = philo_array->tmp->philo_num;
	ptr = (pthread_t *)malloc(sizeof(pthread_t) * num);
	while (i < num)
	{
		pthread_create(&(ptr[i]), NULL, cycle_of_boring_life, \
		(void *)&(philo_array[i]));
		i++;
	}
	pthread_create(&(death), NULL, philo_die, (void *)(philo_array));
	pthread_join(death, NULL);
	pthread_detach(death);
	free (ptr);
}

void	*philo_die(void *arg)
{
	t_philo	*philo;
	int		i;
	int		well_fed;
	int		num;

	i = 0;
	philo = (t_philo *)arg;
	while (1)
	{
		if (my_get_time() >= philo[i].time_end)
		{
			print(5, my_get_time() - philo->tmp->start_time, philo->index, \
			&(philo->tmp->message));
			break ;
		}
		if (philo[0].tmp->amount_eat != -1)
		{
			well_fed = 0;
			num = -1;
			while (++num < philo->tmp->philo_num)
			{
				if (philo[num].num_eat >= philo[0].tmp->amount_eat)
					well_fed++;
			}
			if (well_fed == philo->tmp->philo_num)
				break ;
		}
		i = (i + 1) % philo->tmp->philo_num;
	}
	return (NULL);
}
