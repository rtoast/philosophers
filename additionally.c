#include "philo.h"

void	ft_error(char *str)
{
	printf("%s\n", str);
	exit (0);
}

int		valid(char *str)
{
	int	flag;
	int	i;

	i = -1;
	flag = 0;
	while (str[++i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			flag = -1;
			break ;
		}
	}
	return (flag);
}

void	filing(char *str, int i, t_init *tmp)
{
	if (i == 1)
		tmp->philo_num = ft_atoi(str);
	if (i == 2)
		tmp->time = ft_atoi(str);
	if (i == 3)
		tmp->eat = ft_atoi(str);
	if (i == 4)
		tmp->sleep = ft_atoi(str);
	if (i == 5)
		tmp->amount_eat = ft_atoi(str);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
