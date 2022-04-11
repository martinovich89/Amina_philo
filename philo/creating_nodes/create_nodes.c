#include "../philo.h"

void	circularing(t_philo **a)
{
	t_philo	*copy;
	t_philo	*head;

	copy = *a;
	head = *a;
	while (copy->next != NULL)
    {
		copy = copy->next;
    }
	copy->next = head;
	head->previous = copy;
}

void    incr_id_fork(t_philo **philo_fi, t_glob_info *infos)
{
    t_philo *copy;
    int i;

    copy = *philo_fi;
    i = 0;
    while(i < (infos->nb_philos))
    {
        copy->id = i + 1;
        copy = copy->next;
        i++;
    }
}

void    create_all_philos(t_philo *philo_fi, t_philo *philo_sec, t_glob_info *infos)
{
    int i;
    t_philo *philo_last;

    i = 2;
    while(i < infos->nb_philos)
    {
        philo_last = ft_lstnew(infos);
		ft_exit(philo_last);
		philo_last->next = philo_fi;
        philo_sec->next = philo_last;
        philo_last->previous = philo_sec;
        philo_fi->previous = philo_last;
        philo_sec = philo_last;
		i++;
    }
    i = 0;
    philo_last = philo_fi;
    while (i < infos->nb_philos)
    {
        philo_last = philo_last->next;
        i++;
    }
}

t_philo *create_ll(t_glob_info *infos)
{
    t_philo *philo_fi;
    t_philo *philo_sec;

    if (infos->nb_philos > 0)
    {
        philo_fi = ft_lstnew(infos);
        ft_exit(philo_fi);
        if (infos->nb_philos == 1)
            return (philo_fi); 
        else
        {
            philo_sec = ft_lstnew(infos);
            ft_exit(philo_sec);
            philo_fi->next = philo_sec;
            philo_sec->previous = philo_fi;
            create_all_philos(philo_fi, philo_sec, infos);
        }
        return (philo_fi);
    }
    else
        return (NULL);
}