/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:32:05 by rtoast            #+#    #+#             */
/*   Updated: 2021/09/15 23:34:02 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	my_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_sleep(int time)
{
	int	start;

	start = my_get_time();
	while ((my_get_time() - start) < time)
		usleep(20);
}

void	print(int i, int time, int index, pthread_mutex_t *mas)
{
	pthread_mutex_lock(mas);
	if (i == 1)
		printf(GREEN"%4d: "RESET"%3d "YELLOW"philo has taken a fork\n", \
															time, index);
	if (i == 2)
		printf(GREEN"%4d: "RESET"%3d "BLUE"philo eating\n", time, index);
	if (i == 3)
		printf(GREEN"%4d: "RESET"%3d "MAGENTA"philo sleeping\n", time, index);
	if (i == 4)
		 printf(GREEN"%4d: "RESET"%3d "CYAN"philo thinking\n", time, index);
	if (i == 5)
	{
		 printf(RED"%4d: %3d PHILO IS DIE\n", time, i);
		 return ;
	}
	pthread_mutex_unlock(mas);
}
