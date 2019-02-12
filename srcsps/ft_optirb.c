/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optirb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 13:49:36 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/12 16:27:39 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_optirb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
	t_opti	*prev;
	char	*dup;

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
		if (!(dup = ft_strdup("rr\n")))
			return ;
		tmp->str = dup;
		//ft_strdel(&dup);
	}
	*listopt = tmp;
}

void	ft_optirrb(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
	t_opti	*prev;
	char	*dup;

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
		if (!(dup = ft_strdup("rrr\n")))
			return ;
		tmp->str = dup;
	//	ft_strdel(&dup);
	}
	*listopt = tmp;
}
