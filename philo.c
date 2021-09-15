/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:31:22 by rtoast            #+#    #+#             */
/*   Updated: 2021/09/15 23:31:43 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_init	*tmp;
	t_philo	*philo_array;

	tmp = NULL;
	philo_array = NULL;
	if (argc != 5 && argc != 6)
		ft_error("Wrong amount of arguments: meow :(");
	tmp = init_tmp(tmp, argv);
	philo_array = create_array(tmp);
	create_flow(philo_array);
	if (tmp)
		free(tmp);
	if (philo_array[0].left)
		free(philo_array[0].left);
	if (philo_array)
		free(philo_array);
}
