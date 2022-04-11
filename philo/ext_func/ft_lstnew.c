#include "../philo.h"

t_philo	*ft_lstnew(t_glob_info *infos)
{
	t_philo	*new;

	new = malloc(sizeof (t_philo));
	if (new == NULL)
		return (NULL);
	new -> next = NULL;
	new -> previous = NULL;
	new->id = 1;
	new->nb_fork = 1;
	new->own_fork_id = 1;
	new->other_fork_id = 1;
	new->meals_eaten = 0;
	new->living = 1;
	new->start_eating = convert_toms();
	new->is_sleeping = convert_toms();
	new->is_thinking = convert_toms();
	new->died = convert_toms();
	new->last_meal = convert_toms();
	new->got_fork = convert_toms();
	new->glob_infos = infos;
	pthread_mutex_init(&new->p_fork, NULL);
	//new->th = 1;
	//new->p_fork = 0;
	// if	(pthread_mutex_init((*new).p_fork, NULL) != 0)
	// 	perror("Error : Failed to init a mutex ");
	// new.states.eating = 'F';
	// new->states.sleeping = 'F';
	// new->states.thinking = 'F';
	// new->states.dying = 'F';
	return (new);
}
