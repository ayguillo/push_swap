/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortopti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:05:10 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/30 17:02:06 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_minhere(t_pslist **lista, t_pslist **listb, int lenla)
{
	int		i;
	int		min;

	i = 0;
	min = ft_min(*lista, &i);
	if (i < lenla / 2)
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

	i = 0;
	max = ft_max(*lista, &i);
	if (i == lenla - 1 || i == 0)
		return ;
	if (i < lenla / 2)
	{
		while ((*lista)->content != max)
			ft_exec_inst(lista, listb, "ra");
		ft_exec_inst(lista, listb, "ra");
	}
	else
	{
		while ((*lista)->content != max)
			ft_exec_inst(lista, listb, "rra");
		ft_exec_inst(lista, listb, "ra");
	}
}

static int		ft_find(t_pslist *lista, int content)
{
	int			i;
	int			min;
	int			max;
	t_pslist	*tmp;

	i = 0;
	min = ft_min(lista, &i);
	tmp = lista;
	if (content < min)
		return (-1);
	max = ft_max(lista, &i);
	if (content > max)
		return (ft_pslstlen(lista));
	i = 0;
	while (lista->content != min)
	{
		lista = lista->next;
		i++;
	}
	while (lista->content < content)
	{
		if (!lista->next)
		{
			if (lista->content < content && tmp->content > content)
				return ft_pslstlen(tmp);
			i = 0;
			lista = tmp;
		}
		lista = lista->next;
		i++;
	}
	return (i);
}

void		ft_sortopti(t_pslist **lista, t_pslist **listb)
{
	int		find;
	int		lenla;
	int		i;

	while (ft_pslstlen(*lista) > 3)
		ft_exec_inst(lista, listb, "pb");
	ft_shortsort(lista, listb);
	while (*listb)
	{
		ft_printlist_nb(*lista);
		find = ft_find(*lista, (*listb)->content);
		lenla = ft_pslstlen(*lista);
		printf("find = %i\nlen/2 = %i\nlen = %i\ncontent = %i\nlen mod = %i\n", find, lenla / 2, lenla, (*listb)->content, lenla % 2);
		if (find == -1)
			ft_minhere(lista, listb, lenla);
		else if (find == lenla)
			ft_maxhere(lista, listb, lenla);
		else
		{
			i = -1;
			if (find < lenla / 2)
			{
				while (++i < find)
					ft_exec_inst(lista, listb, "ra");
			}
			else
				while (++i < ft_pslstlen(*lista) - find)
					ft_exec_inst(lista, listb, "rra");
		}
		ft_exec_inst(lista, listb, "pa");
	}
	ft_minhere(lista, listb, lenla);
}
