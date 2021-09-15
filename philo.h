#ifndef PHILO_H
# define PHILO_H

# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"

typedef struct	s_init
{
	int			philo_num;
	int			time;
	int			sleep;
	int			eat;
	int			amount_eat;
	int			start_time;
}				t_init;

typedef struct	s_philo
{
	pthread_mutex_t *left;
	pthread_mutex_t *right;
	t_init			*tmp;
	int				index;
	int				time_end;
}				t_philo;

void	ft_error(char *str);
t_init	*init_tmp(t_init *tmp, char **argv);
int		valid(char *str);
int		ft_atoi(char *str);
void	pars_argument(t_init *tmp, char **argv);
void	filing(char *str, int i, t_init *tmp);
void	*cycle_of_boring_life(void *arg);
void	create_flow(t_philo *philo_array);
int		my_get_time(void);
void	my_sleep(int time);
t_philo	*create_array(t_init *tmp);
pthread_mutex_t	*create_fork_array(int num);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	*philo_die(void *arg);

#endif
