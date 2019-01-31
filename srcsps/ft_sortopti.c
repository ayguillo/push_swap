/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortopti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:05:10 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/31 10:32:22 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static void		ft_minhere(t_pslist **lista, t_pslist **listb, int lenla)
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
	printf("i == %i\nlen = %i\n",i, lenla);
	if (i == 0)
		ft_exec_inst(lista, listb, "ra");
	else if (i <= lenla / 2)
	{
		while ((*lista)->content != max)
			ft_exec_inst(lista, listb, "ra");
	}
	else
	{
		while (i < lenla - 1)
		{
			ft_exec_inst(lista, listb, "rra");
			i++;
		}
	}
}*/

static int		ft_foundpath(t_pslist *listb, int lenlb)
{
	int		i;
	int		max;
	int		j;
	int		min;

	i = 0;
	j = 0;
	max = ft_max(listb, &i);
	min = ft_min(listb, &j);
	max = i;
	min = j;
	while ((max > 1 || min > 1))
	{
		max--;
		min--;
		listb = listb->next;
	}
	printf("min = %i\nmax = %i\n", min, max);
	if (max == 0 && i < lenlb / 2)
		return (i);
	if (min == 0 && j < lenlb / 2)
		return (j);
	if (max == 0 && i > lenlb / 2 && j > i)
		return (j);
	if (min == 0 && j > lenlb / 2 && i > j)
		return (i);
	return (0);
}

void		ft_sortopti(t_pslist **lista, t_pslist **listb)
{
//	int		find;
	int		lenla;
//	int		i;

	lenla = ft_pslstlen(*listb);
/*	while (ft_pslstlen(*lista) > 3)
		ft_exec_inst(lista, listb, "pb");
	ft_shortsort(lista, listb);*/
	printf("found %i\n", ft_foundpath(*lista, ft_pslstlen(*lista)));
}
