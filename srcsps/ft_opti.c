/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 11:42:40 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 15:45:15 by ayguillo         ###   ########.fr       */
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
	while (!(ft_strcmp((*listopt)->str, "rra\n")) && (*listopt)->next)
	{
		prev = *listopt;
		*listopt = (*listopt)->next;
	}
	if (!(ft_strcmp((*listopt)->str, "rrb\n")))
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

static void	ft_optira(t_opti **listopt)
{
	t_opti	*tmp;
	t_opti	*suppr;
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

t_opti		*ft_optinst(t_opti *listopt)
{
	int		i;
	t_opti	*tmp;

	i = 0;
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
		i++;
	}
	listopt = tmp;
	return (listopt);
}
