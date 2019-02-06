/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:42:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/06 15:24:32 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_opti		*ft_pushbackstr(char *str, t_opti *listopt)
{
	t_opti		*nvel;
	t_opti		*tmp;
	char		*dup;

	if (!(dup = ft_strdup(str)))
		return (NULL);
	if (!(nvel = malloc(sizeof(t_opti))))
		return (NULL);
	if (!(nvel->str = dup))
	{
		ft_strdel(&dup);
		free(nvel);
		return (NULL);
	}
	nvel->next = NULL;
	if (!listopt)
		return (nvel);
	tmp = listopt;
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
	t_opti	*suppr;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "rra")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rrb")))
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

static void	ft_optira(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
	t_opti	*prev;

	tmp = *listopt;
	while (!(ft_strcmp((*listopt)->str, "ra")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rb")))
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

void		ft_optinst(t_opti **listopt)
{
	int		i;
	t_opti	*tmp;

	i = 0;
	tmp = *listopt;
	while (*listopt)
	{
		if (!(ft_strcmp((*listopt)->str, "ra")))
			ft_optira(listopt);
		else if (!(ft_strcmp((*listopt)->str, "rra")))
			ft_optirra(listopt);
		else if (!(ft_strcmp((*listopt)->str, "rb")))
			ft_optirb(listopt);
		else if (!(ft_strcmp((*listopt)->str, "rrb")))
			ft_optirrb(listopt);
		else if (!(ft_strcmp((*listopt)->next->str, "rra")))
			ft_optidoublera(listopt);
		*listopt = (*listopt)->next;
		i++;
	}
}
