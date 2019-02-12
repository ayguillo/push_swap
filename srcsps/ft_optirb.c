/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optirb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:49:36 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/12 14:52:22 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_optirb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
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
		{
			suppr = *listopt;
			*listopt = (*listopt)->next;
			prev->next = *listopt;
			free(suppr);
		}
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		tmp->str = "rr\n";
	}
	*listopt = tmp;
}

void	ft_optirrb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
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
		{
			suppr = *listopt;
			*listopt = (*listopt)->next;
			prev->next = *listopt;
			free(suppr);
		}
		else
			ft_supprlast(listopt, prev);
		ft_strdel(&tmp->str);
		tmp->str = "rrr\n";
	}
	*listopt = tmp;
}

void	ft_optidoublera(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*prev;
	t_opti	*suppr;
	t_opti	*suppr2;

	tmp = *listopt;
	prev = *listopt;
	if ((*listopt)->next)
		*listopt = (*listopt)->next;
	if (((*listopt)->next) && !(ft_strcmp((*listopt)->next->str, "ra\n")))
	{
		suppr = tmp->next;
		*listopt = (*listopt)->next;
		suppr2 = *listopt;
		*listopt = (*listopt)->next;
		prev->next = (*listopt);
		ft_strdel(&suppr->str);
		ft_strdel(&suppr2->str);
		free(suppr);
		free(suppr2);
		tmp->next = *listopt;
	}
	*listopt = tmp;
}
