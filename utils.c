#include "philo.h"

int	my_get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	my_sleep(int time)
{
	int start;

	start = my_get_time();
	while((my_get_time() - start) < time)
		usleep(20);
}