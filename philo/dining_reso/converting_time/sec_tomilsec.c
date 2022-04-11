#include "../../philo.h"

time_t convert_toms()
{
    struct timeval  time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_usleep(t_philo *philo, time_t t)
{
	time_t	start;

	start = convert_toms();
    //printf("%ld\n", start);
	while (1)
	{
		//printf("%ld\n", convert_toms() - start);
		if (check_dead(philo, philo->last_meal, philo->glob_infos->time_to_die) == 1)
			break;
		if (convert_toms() - start >= t)
			break ;
		usleep(200);
	}
}

int	my_usleep_to_check(time_t t)
{
	time_t	start;

	start = convert_toms();
    //printf("%ld\n", start);
	while (1)
	{
		// printf("%ld\n", convert_toms() - start);
		if (convert_toms() - start >= t)
			return (1) ;
		usleep(200);
	}
}

time_t	countdown(time_t time)
{
	return (convert_toms() - time);
}
