/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optirb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:49:36 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/04 17:59:41 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_optirb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rb")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "ra")))
	{
		if ((*listopt)->next)
		{
			suppr = *listopt;
			*listopt = (*listopt)->next;
			prev->next = *listopt;
			free(suppr);
		}
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		tmp->str = "rr";
	}
	*listopt = tmp;
}

void	ft_optirrb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rrb")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rra")))
	{
		if ((*listopt)->next)
		{
			suppr = *listopt;
			*listopt = (*listopt)->next;
			prev->next = *listopt;
			free(suppr);
		}
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		tmp->str = "rrr";
	}
	*listopt = tmp;
}
