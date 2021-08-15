#include "philo.h"

t_init	*init_tmp(t_init *tmp, char **argv)
{
	tmp = (t_init *)malloc(sizeof(t_init));
	pars_argument(tmp, argv);
	return (tmp);
}

void	pars_argument(t_init *tmp, char **argv)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (argv[++i])
	{
		error = valid(argv[i]);
		if (error == -1)
			ft_error("Not valid arguments");
		else
			filing(argv[i], i, tmp);
	}
}
