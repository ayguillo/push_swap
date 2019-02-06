/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/06 15:25:58 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 **count = tab[0]
 **countmin = tab[1]
 **content = tab[2]
 **controlea = tab[3]
 **controleb = tab[4]
 **counta = tab[5]
*/

static int	ft_count(t_pslist *lista, t_pslist *listb, int *waya, int *wayb)
{
	int 		tab[6];
	t_pslist	*tmp;
	int			lena;
	int			lenb;

	tab[0] = 0;
	tab[2] = 0;
	tab[1] = 2147483647;
	tab[4] = 0;
	*waya = 1;
	*wayb = 1;
	tmp = lista;
	lena = ft_pslstlen(lista);
	lenb = ft_pslstlen(listb);
	if (lenb == 1)
		return(listb->content);
	while (listb->next)
	{
		tab[3] = 0;
		tab[5] = 1;
		tmp = lista;
		while (tab[5] < lena && tmp->next)
		{
			if (tmp->content < listb->content
					&& tmp->next->content > listb->content)
				break;
			tmp = tmp->next;
			tab[3]++;
			tab[5]++;
			tab[0]++;
			if (tab[3] > lena / 2)
			{
				tab[3] = tab[3] - lenb / 2;
				tab[0] = tab[0] - lena / 2;
				*waya = -1;
			}
			if (tab[5] == lena)
			{
				tab[5] = 0;
				tab[0] = tab[0] - lena;
			}
		}
		listb = listb->next;
		tab[4]++;
		tab[0]++;
		if (tab[4] > lenb / 2)
		{
			tab[4] = tab[4] - lenb / 2;
			tab[0] = tab[0] - lenb / 2;
			*wayb = -1;
		}
		if (tab[1] > tab[0])
		{
			tab[2] = listb->content;
			tab[1] = tab[0];
		}
		tab[0] = tab[0] - tab[3] + 1;
	}
	return (tab[2]);
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
	int			waya;
	int			wayb;
	int			count;
	int			min;

	waya = 0;
	wayb = 0;
	while (ft_pslstlen(*lista) > 3)
		ft_movemaxmin(lista, listb, listopt);
	ft_shortsort(lista, listb, listopt);
//	ft_printlist_nb(*lista);
	while ((*listb)->next)
	{
		count = ft_count(*lista, *listb, &waya, &wayb);
		while ((*listb)->content != count) 
		{
			if (wayb == -1)
				ft_exec_inst(lista, listb, "rrb", listopt);
			else
				ft_exec_inst(lista, listb, "rb", listopt);
		}
		if ((*listb)->content - (*lista)->content > 0 && waya == 1)
			while ((*listb)->content - (*lista)->content > 0)
				ft_exec_inst(lista, listb, "ra", listopt);
		else if (((*listb)->content - (*lista)->content < 0 && waya == 1))
		{
			while ((*listb)->content - (*lista)->content < 0)
				ft_exec_inst(lista, listb, "ra", listopt);
			ft_exec_inst(lista, listb, "ra", listopt);
		}
		else if (((*listb)->content - (*lista)->content < 0 && waya == -1))
		{
			while ((*listb)->content - (*lista)->content < 0)
				ft_exec_inst(lista, listb, "rra", listopt);
			ft_exec_inst(lista, listb, "ra", listopt);
		}
		else if ((*listb)->content - (*lista)->content > 0 && waya == -1)
			while ((*listb)->content - (*lista)->content > 0)
				ft_exec_inst(lista, listb, "ra", listopt);
		ft_exec_inst(lista, listb, "pa", listopt);
//		ft_printlist_nb(*lista);
	}
	waya = 0;
	min = ft_min(*lista, &waya);
	if (waya > ft_pslstlen(*lista) / 2)
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "rra", listopt);
	else
		while ((*lista)->content != min)
			ft_exec_inst(lista, listb, "ra", listopt);
}
