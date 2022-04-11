/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:07:23 by ael-khat          #+#    #+#             */
/*   Updated: 2022/02/17 18:07:31 by ael-khat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstdelone(t_philo *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->data);
	free(lst);
}
