/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optirb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:49:36 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 13:50:51 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_supproneel(t_opti **listopt, t_opti *prev)
{
	t_opti *suppr;

	suppr = *listopt;
	*listopt = (*listopt)->next;
	prev->next = *listopt;
	ft_strdel(&suppr->str);
	free(suppr);
}

void	ft_optirb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rb\n")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "ra\n")))
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

void	ft_optirrb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rrb\n")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rra\n")))
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
