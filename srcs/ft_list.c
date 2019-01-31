/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:06:04 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/31 13:43:25 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>

t_pslist	*ft_delhead(t_pslist *list)
{
	t_pslist	*tmp;

	if (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
		tmp = NULL;
		return (list);
	}
	return (NULL);
}

void		ft_delallst(t_pslist **list)
{
	t_pslist *tmp;

	while (*list)
	{
		tmp = (*list)->next;
		*list = ft_delhead(*list);
		*list = tmp;
	}
}

t_pslist	*ft_addl(t_pslist *list, int nw)
{
	t_pslist	*tmp;

	if (!(tmp = malloc(sizeof(t_pslist))))
		return (NULL);
	if (!list)
	{
		tmp->content = nw;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = nw;
		tmp->next = list;
	}
	return (tmp);
}

t_pslist	*ft_addr(t_pslist *list, int nw)
{
	t_pslist	*nvel;
	t_pslist	*tmp;

	if (!(nvel = malloc(sizeof(t_pslist))))
		return (NULL);
	nvel->content = nw;
	nvel->next = NULL;
	if (!list)
		return (nvel);
	tmp = list;
	while (tmp->next)
	{
		if (tmp->content == nvel->content)
			return (NULL);
		tmp = tmp->next;
	}
	if (tmp->content == nvel->content)
		return (NULL);
	tmp->next = nvel;
	return (list);
}

void		ft_printlist_nb(t_pslist *list)
{
	t_pslist *head;

	head = list;
	ft_printf("____LIST_____\n");
	while (head)
	{
		ft_printf("%i\n", head->content);
		head = head->next;
	}
	ft_printf("____ENDLIST_____\n");
}
