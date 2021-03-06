/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 14:18:33 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_best_waya(t_pslist *lista, int content)
{
	int			len;
	int			count;
	t_pslist	*tmp;

	len = ft_pslstlen(lista);
	count = 0;
	tmp = lista;
	while (lista->next)
	{
		if (lista->content < content && lista->next->content > content)
			break ;
		lista = lista->next;
		count++;
	}
	if (count == len - 1)
		return (tmp->content);
	return (lista->next->content);
}

int			ft_best(t_pslist *lista, t_pslist *listb, int len)
{
	int			rotate;
	int			rotatea;
	int			tot;
	t_pslist	*save;

	rotate = 0;
	tot = 2147483647;
	if (len == 1)
		return (listb->content);
	while (listb)
	{
		rotatea = ft_best_waya(lista, listb->content);
		if (ft_abs(rotatea) + rotate < tot)
		{
			save = listb;
			tot = ft_abs(rotatea) + rotate;
		}
		listb = listb->next;
		rotate++;
	}
	return (save->content);
}

int			ft_go(t_pslist *list, int content)
{
	int		i;

	i = 0;
	while (list->content != content)
	{
		list = list->next;
		i++;
	}
	return (i);
}

static void	ft_movemaxmin(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int	min;
	int	max;

	min = ft_min(*lista, &min);
	max = ft_max(*lista, &max);
	if ((*lista)->content == min || (*lista)->content == max)
		ft_exec_inst(lista, listb, "ra\n", listopt);
	else
		ft_exec_inst(lista, listb, "pb\n", listopt);
}

void		ft_insertsort(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int		min;
	int		i;

	while (ft_pslstlen(*lista) > 3)
		ft_movemaxmin(lista, listb, listopt);
	ft_shortsort(lista, listb, listopt);
	while (*listb)
	{
		ft_loop(lista, listb, listopt);
		ft_exec_inst(lista, listb, "pa\n", listopt);
	}
	i = 0;
	min = ft_min(*lista, &i);
	if (i <= ft_pslstlen(*lista) / 2)
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "ra\n", listopt);
	else
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "rra\n", listopt);
}
