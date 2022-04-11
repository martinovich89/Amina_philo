#include "../philo.h"

void	ft_exit(t_philo *list)
{
	if (!list)
	{
		write(2, "Error malloc\n", 14);
		exit(0);
	}
}