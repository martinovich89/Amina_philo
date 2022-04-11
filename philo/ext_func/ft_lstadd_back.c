#include "../philo.h"

void	ft_lstadd_back(t_philo **alst, t_philo *new)
{
	t_philo	*last;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	last = ft_lstlast(*alst);
	last -> next = new;
	new->previous = last;
	new->next = NULL;
}
