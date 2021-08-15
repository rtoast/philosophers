#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
// # include "pthread.h"
// # include "sys/time.h"

typedef struct	s_init
{
	int			philo_num;
	int			time;
	int			sleep;
	int			eat;
	int			amount_eat;
}				t_init;

void	ft_error(char *str);
t_init	*init_tmp(t_init *tmp, char **argv);
int		valid(char *str);
int		ft_atoi(char *str);
void	pars_argument(t_init *tmp, char **argv);
void	filing(char *str, int i, t_init *tmp);

#endif
