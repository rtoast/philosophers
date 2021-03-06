/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:37:30 by rtoast            #+#    #+#             */
/*   Updated: 2021/09/15 23:37:59 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*create_array(t_init *tmp)
{
	pthread_mutex_t	*array_fork;
	t_philo			*philo_array;
	int				i;

	i = 0;
	array_fork = create_fork_array(tmp->philo_num);
	philo_array = (t_philo *)malloc(sizeof(t_philo) * tmp->philo_num);
	while (i < tmp->philo_num)
	{
		philo_array[i].index = i;
		philo_array[i].left = &(array_fork[i]);
		philo_array[i].right = &(array_fork[(i + 1) % tmp->philo_num]);
		philo_array[i].tmp = tmp;
		philo_array[i].time_end = my_get_time() + tmp->time;
		philo_array[i].num_eat = 0;
		i++;
	}
	return (philo_array);
}

pthread_mutex_t	*create_fork_array(int num)
{
	pthread_mutex_t	*array;
	int				i;

	i = 0;
	array = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	while (i < num)
	{
		pthread_mutex_init(&(array[i]), NULL);
		i++;
	}
	return (array);
}
