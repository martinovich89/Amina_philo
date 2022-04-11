#include "philo.h"

void    destroy_mutexes(t_philo *philo)
{
    int i;

    i = 0;
    while (i < philo->glob_infos->nb_philos)
    {
        pthread_mutex_destroy(&philo->p_fork);
        i++;
        philo = philo->next;
    }
	pthread_mutex_destroy(&philo->glob_infos->is_alive);
	pthread_mutex_destroy(&philo->glob_infos->eating);
	pthread_mutex_destroy(&philo->glob_infos->msg);
}

int main(int argc, char *argv[])
{
    t_glob_info *global_info;
    t_philo     *philo;
    int			i;
	t_philo		*start;
	t_philo		*backup;

	i = 0;
    if (argc > 6 || (argc < 6 && argc != 5))
    {
        write (1, "Error : Number of args is incorrect", 36);
        exit(1);
    }
    else
    {
        if (check_char(argv) == 0)
        {
            write (1, "Error : Args contains characters", 33);
            return (0);
        }
        global_info = get_info_args(argc, argv);
        philo = create_ll(global_info);
		
		backup = philo;
		incr_id_fork(&philo, global_info);

		i = 0;

		start = philo;
		while (i < global_info->nb_philos)
		{
			if (start->id % 2 != 0)
			{
				start->first = &start->p_fork;
				start->second = &start->next->p_fork;
			}
			else
			{
				start->second = &start->p_fork;
				start->first = &start->next->p_fork;
			}
			start = start->next;
			i++;
		}
		philo = backup;

        dining_philos(&philo, global_info);
        destroy_mutexes(philo);
        return (0);
    }
    
}

void    print_lst(t_philo **phi, t_glob_info *infos)
{
    t_philo *philo_fi;
    int     i;

    philo_fi = *phi;
    i = 0;
    while(i < infos->nb_philos)
    {
        philo_fi = philo_fi->next;
        i++;
    }
}