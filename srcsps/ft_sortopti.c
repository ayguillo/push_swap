/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortopti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:05:10 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/31 17:20:41 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_minhere(t_pslist **lista, t_pslist **listb, int lenla)
{
	int		i;
	int		min;

	i = 0;
	min = ft_min(*lista, &i);
	if (i <= lenla / 2)
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "ra");
	else
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "rra");
}

static void		ft_maxhere(t_pslist **lista, t_pslist **listb, int lenla)
{
	int			i;
	int			max;
	t_pslist	*tmp;

	i = 0;
	max = ft_max(*lista, &i);
	tmp = *lista;
	if (i == 0)
		ft_exec_inst(lista, listb, "ra");
	else if (i <= lenla / 2)
	{
		while ((*lista)->content != max)
			ft_exec_inst(lista, listb, "ra");
		ft_exec_inst(lista, listb, "ra");
	}
	else
	{
		while (i < lenla)
		{
			printf("coucou");
			ft_exec_inst(lista, listb, "rra");
			i++;
		}
	}
}

static void		ft_pushhere(t_pslist **lista, t_pslist **listb, int who,
		int content)
{
	t_pslist	*tmp;
	int			lenla;

	tmp = *lista;
	lenla = ft_pslstlen(tmp);
	while (list->next)
	{
		if (list->content)
	}
	if (i == 0)
		ft_exec_inst(lista, listb, "ra");
	else if (i <= lenla / 2)
	{
		while ((*lista)->content != max)
			ft_exec_inst(lista, listb, "ra");
		ft_exec_inst(lista, listb, "ra");
	}
	else
	{
		while (i < lenla)
		{
			printf("coucou");
			ft_exec_inst(lista, listb, "rra");
			i++;
		}
	}
}

static int		ft_foundpath(t_pslist *listb, int lenlb, int *way, int *who)
{
	int		i;
	int		max;
	int		j;
	int		min;

	i = 0;
	j = 0;
	max = ft_max(listb, &i);
	min = ft_min(listb, &j);
	if (j < lenlb / 2)
		max = j;
	else
		max = lenlb - j;
	if (i < lenlb / 2)
		min = i;
	else
		min = lenlb - i;
	if (min < max && i < lenlb / 2)
	{
		*who = -1;
		*way = -1;
		return (min);
	}
	if (max < min && j < lenlb / 2)
	{
		*way = -1;
		return (max);
	}
	if (min < max)
	{
		*who = -1;
		return (min);
	}
	return (max);
}

void		ft_sortopti(t_pslist **lista, t_pslist **listb)
{
	int		find;
	int		lenla;
	int		i;
	int		way;
	int		who;

	lenla = ft_pslstlen(*lista) + 1;
	while (--lenla > 3)
		ft_exec_inst(lista, listb, "pb");
	ft_shortsort(lista, listb);
	while (listb)
	{
		i = -1;
		way = 1;
		who = 1;
		ft_printf("\nlista\n");
		ft_printlist_nb(*lista);
		ft_printf("\nlistb\n");
		ft_printlist_nb(*listb);
		find = ft_foundpath(*listb, ft_pslstlen(*listb), &way, &who);
		if (way == 1)
			while (++i <= find)
				ft_exec_inst(lista, listb, "rb");
		else
			while (++i <= find)
				ft_exec_inst(lista, listb, "rrb");
		if (who == -1 && listb->content > ft_min(*lista, &i));
	}
}
