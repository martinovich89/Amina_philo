#include "../philo.h"

void	ft_lstadd_front(t_philo **alst, t_philo *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	if (!new)
		return ;
	new->next = *alst;
	new->previous = NULL;
	*alst = new;
}
