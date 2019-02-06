/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/06 17:54:40 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_best_waya(t_pslist *lista, t_pslist *listb)
{
	int			content;
	t_pslist	*tmp;
	int			rotate;
	int			len;

	content = listb->content;
	tmp = lista;
	rotate = 0;
	len = ft_pslstlen(lista);
	while (tmp->next)
	{
		if (tmp->content < content && tmp->next->content > content)
		{
			rotate++;
			break;
		}
		tmp = tmp->next;
		rotate++;
	}
	return (rotate > len / 2 ? ((rotate - len / 2) * -1) : rotate);
}

static int	ft_best(t_pslist *lista, t_pslist *listb, int len)
{
	t_pslist	*tmp;
	int			rotate;
	int			rotatea;
	int			save;
	int			tot;

	tmp = listb;
	rotate = 0;
	tot = 2147483647;
	while (tmp)
	{
		rotatea = ft_best_waya(lista, tmp);
		if (ft_abs(rotatea) + rotate < tot)
		{
			save = rotate;
			tot = ft_abs(rotatea) + rotate;
		}
		tmp = tmp->next;
		rotate++;

	}
	return (save > len / 2 ? ((save - len / 2) * -1) : save);
}

static void	ft_movemaxmin(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int	min;
	int	max;

	min = ft_min(*lista, &min);
	max = ft_max(*lista, &max);
	if ((*lista)->content == min || (*lista)->content == max)
		ft_exec_inst(lista, listb, "ra", listopt);
	else
		ft_exec_inst(lista, listb, "pb", listopt);
}

void		ft_insertsort(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int	waya;
	int	wayb;
	int	lenb;
	int	i;

	while (ft_pslstlen(*lista) > 3)
		ft_movemaxmin(lista, listb, listopt);
	ft_shortsort(lista, listb, listopt);
	ft_printlist_nb(*lista);
	while (*listb)
	{
		ft_printlist_nb(*lista);
		i = -1;
		lenb = ft_pslstlen(*listb);
		wayb = ft_best(*lista, *listb, lenb);
		if (wayb < 0)
			while (++i < ft_abs(wayb) - 1)
				ft_exec_inst(lista, listb, "rrb", listopt);
		else
			while (++i < wayb)
				ft_exec_inst(lista, listb, "rb", listopt);
		waya = ft_best_waya(*lista, *listb);
		i = -1;
		if (waya < 0)
		{
			while (++i < ft_abs(waya) - 1)
				ft_exec_inst(lista, listb, "rra", listopt);
		}
		else
			while (++i < waya)
				ft_exec_inst(lista, listb, "ra", listopt);
		ft_exec_inst(lista, listb, "pa", listopt);
	}
}
