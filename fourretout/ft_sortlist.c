/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 12:42:24 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/22 18:38:22 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init(t_pslist **list, t_pslist **last)
{
	t_pslist	*tmp;
	t_pslist	*tmpprev;

	tmp = *list;
	while (tmp->next->next)
		tmp = tmp->next;
	tmpprev = tmp;
	*last = tmp->next;
	(*last)->prev = tmpprev;
}

void		ft_sortlist(t_pslist **list, t_pslist *start, t_pslist *last)
{

}

int		main(void)
{
	t_pslist	*list;

	list = ft_addr(NULL, 12);
	list = ft_addr(list, 14);
	list = ft_addr(list, 10);
	ft_sortlist(&list, list, list->last);
}
