/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtoast <rtoast@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 23:36:17 by rtoast            #+#    #+#             */
/*   Updated: 2021/09/15 23:36:19 by rtoast           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_init	*init_tmp(t_init *tmp, char **argv)
{
	tmp = (t_init *)malloc(sizeof(t_init));
	pars_argument(tmp, argv);
	tmp->start_time = my_get_time();
	pthread_mutex_init(&(tmp->message), NULL);
	return (tmp);
}

void	pars_argument(t_init *tmp, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	tmp->amount_eat = -1;
	while (argv[++i])
	{
		error = valid(argv[i]);
		if (error == -1)
			ft_error("Not valid arguments");
		else
			filing(argv[i], i, tmp);
	}
}
