#include "../philo.h"

void    message_tosend(char *str, time_t timestamp, t_philo *philo)
{
	pthread_mutex_lock(&philo->glob_infos->is_alive);
	if (philo->glob_infos->is_dead == 0)
	{
		pthread_mutex_lock(&philo->glob_infos->msg);
		printf(str, timestamp, philo->id);
		pthread_mutex_unlock(&philo->glob_infos->msg);
	}
	pthread_mutex_unlock(&philo->glob_infos->is_alive);
}

void	dying_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->glob_infos->msg);
	printf("[%ld]                                    -   Philo [%d] died\n", countdown(philo->died), philo->id);
	pthread_mutex_unlock(&philo->glob_infos->msg);
	// SOLUTION POSSILE : philo->glob_infos->nb_of_meals = philo->meals_eaten;
	return ;
}

int check_dead(t_philo *philo, time_t last_meal, time_t time_to_die)
{
    pthread_mutex_lock(&philo->glob_infos->is_alive);
    if (philo->glob_infos->is_dead)
    {
        pthread_mutex_unlock(&philo->glob_infos->is_alive);
        return (1);
    }
    if ((convert_toms() - last_meal) >= time_to_die)
    {
        dying_philo(philo);
        philo->glob_infos->is_dead = 1;
        pthread_mutex_unlock(&philo->glob_infos->is_alive);
        return (1);
    }
    pthread_mutex_unlock(&philo->glob_infos->is_alive);
    return (0);
}

void    func_living(t_philo *copy)
{
    if (copy->id % 2 == 0)
        my_usleep(copy, copy->glob_infos->time_to_eat / 3);
    while(copy->glob_infos->nb_of_meals != copy->meals_eaten)
    {
		if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
			break;
		pthread_mutex_lock(copy->first);
		message_tosend("\n[%ld]                                   -   Philo [%d] has taken his fork\n", countdown(copy->got_fork), copy);
		if (copy->glob_infos->nb_philos == 1)
		{
			pthread_mutex_unlock(copy->first);
			usleep(copy->glob_infos->time_to_die * 1000);
			if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die))
				break;
		}
		if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
        {
            pthread_mutex_unlock(copy->first);
			break;
        }
        pthread_mutex_lock(copy->second);
		message_tosend("\n[%ld]                                    -   Philo [%d] has taken the neighbour's fork\n", countdown(copy->got_fork), copy);
		if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
		{
			pthread_mutex_unlock(copy->first);
			pthread_mutex_unlock(copy->second);
			break;
		}
		message_tosend("\n[%ld]                                    -   Philo [%d] is eating\n", countdown(copy->start_eating), copy);
		copy->last_meal = convert_toms();
		if  (copy->glob_infos->nb_of_meals != -1)
			copy->meals_eaten++;
		my_usleep(copy, copy->glob_infos->time_to_eat);
		pthread_mutex_unlock(copy->second);
		pthread_mutex_unlock(copy->first);
		if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
			break;
		message_tosend("\n[%ld]                                    -   Philo [%d] is sleeping\n", countdown(copy->is_sleeping), copy);
		my_usleep(copy, copy->glob_infos->time_to_sleep);
		message_tosend("\n[%ld]                                    -   Philo [%d] is thinking \n", countdown(copy->is_thinking),copy);
        if (check_dead(copy, copy->last_meal, copy->glob_infos->time_to_die) == 1)
			break;
        my_usleep(copy, (copy->glob_infos->time_to_die - (convert_toms() - copy->last_meal)) * 9 / 10);
    }
    return ;
}

void    creating_threads(t_philo *copy, t_glob_info *infos)
{
    long    i;
    t_philo *clone;

    i = 0;
    clone = copy;
    while(i < infos->nb_philos)
    {
        if  (pthread_create(&copy->th, NULL, (void *)func_living, copy) != 0)
        {
            perror("Failed to create a thread\n");
            return ;
        }
        copy = copy->next;
        i++;
    }
    i = 0;
    copy = clone;
    while(i < infos->nb_philos)
    {
        if  (pthread_join(copy->th, NULL) != 0)
        {
            perror("Failed to join a thread\n");
           return ;
        }
        copy = copy->next;
        i++;
    }
}

void    dining_philos(t_philo **philo_fi, t_glob_info *infos)
{
    t_philo *copy;

    copy = *philo_fi;
    creating_threads(copy, infos);
}