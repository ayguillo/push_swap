/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:42:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 13:51:04 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_opti		*ft_pushbackstr(char *str, t_opti *listopt)
{
	t_opti		*nvel;
	t_opti		*tmp;

	tmp = listopt;
	if (!(nvel = malloc(sizeof(t_opti))))
		return (NULL);
	if (!(nvel->str = ft_strdup(str)))
	{
		free(nvel);
		return (NULL);
	}
	nvel->next = NULL;
	if (!listopt)
		return (nvel);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nvel;
	return (listopt);
}

void		ft_supprlast(t_opti **listopt, t_opti *prev)
{
	t_opti		*tmp;

	tmp = *listopt;
	prev->next = NULL;
	free(tmp);
}

static void	ft_optirra(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rra\n")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rrb\n")))
	{
		if ((*listopt)->next)
			ft_supproneel(listopt, prev);
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		if (!(tmp->str = ft_strdup("rrr\n")))
			return ;
	}
	*listopt = tmp;
}

static void	ft_optira(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "ra\n")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rb\n")))
	{
		if ((*listopt)->next)
			ft_supproneel(listopt, prev);
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		if (!(tmp->str = ft_strdup("rr\n")))
			return ;
	}
	*listopt = tmp;
}

t_opti		*ft_optinst(t_opti *listopt)
{
	t_opti	*tmp;

	tmp = listopt;
	while (listopt->next)
	{
		if (!(ft_strcmp(listopt->str, "ra\n")))
			ft_optira(&listopt);
		else if (!(ft_strcmp(listopt->str, "rra\n")))
			ft_optirra(&listopt);
		else if (!(ft_strcmp(listopt->str, "rb\n")))
			ft_optirb(&listopt);
		else if (!(ft_strcmp(listopt->str, "rrb\n")))
			ft_optirrb(&listopt);
		listopt = listopt->next;
	}
	listopt = tmp;
	return (listopt);
}
