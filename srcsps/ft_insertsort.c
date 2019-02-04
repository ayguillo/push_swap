/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/04 17:59:36 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** count = tab[0]
 ** countmin = tab[1]
 ** content = tab[2]
 ** controlea = tab[3]
 ** controleb = tab[4]
 ** counta = tab[5]
 */

static int	ft_count(t_pslist *lista, t_pslist *listb, int *waya, int *wayb)
{
	int 		tab[6];
	t_pslist	*tmp;
	int			len;

	tab[0] = 0;
	tab[1] = 2147483647;
	tab[4] = 0;
	tmp = lista;
	while (listb->next)
	{
		tab[3] = 0;
		tab[5] = 1;
		tmp = lista;
		len = ft_pslstlen(lista);
		while (tab[5] < len && lista->next)
		{
			if (lista->content < listb->content &&
					lista->next->content > listb->content)
				break;
			lista = lista->next;
			tab[3]++;
			tab[5]++;
			tab[0]++;
			if (tab[3] > ft_pslstlen(lista) / 2)
				tab[0] = tab[0] - ft_pslstlen(lista) / 2;
			if (tab[5] == len)
			{
				tab[0] = -1;
				break;
			}
		}
		lista = tmp;
		listb = listb->next;
		tab[4]++;
		tab[0]++;
		if (tab[4] > ft_pslstlen(listb) / 2)
			tab[0] = tab[0] - ft_pslstlen(listb) / 2;
		if (tab[1] > tab[0])
		{
			((tab[3] > ft_pslstlen(listb) / 2) ? (*waya = -1) : (*waya = 1));
			((tab[4] > ft_pslstlen(listb) / 2) ? (*wayb = -1) : (*wayb = 1));
			tab[2] = listb->content;
			tab[1] = tab[0];
		}
		tab[0] = tab[0] - tab[1] + 1;
	}
	return (tab[2]);
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
		ft_exec_inst(lista, listb, "pb", listopt);
	ft_shortsort(lista, listb, listopt);
	while ((*listb)->next)
	{
		ft_printlist_nb(*lista);
		count = ft_count(*lista, *listb, &waya, &wayb);
		while ((*listb)->content != count) 
		{
			if (wayb == -1)
				ft_exec_inst(lista, listb, "rrb", listopt);
			else
				ft_exec_inst(lista, listb, "rb", listopt);
		}
		printf("max %i\n", ft_max(*lista, &wayb));
		if (ft_max(*lista, &wayb) < count)
		{
			wayb = 0;
			min = ft_min(*lista, &wayb);
			if (wayb < ft_pslstlen(*lista) / 2)
				while ((*lista)->content != min)
					ft_exec_inst(lista, listb, "ra", listopt);
			else
				while ((*lista)->content != min)
					ft_exec_inst(lista, listb, "rra", listopt);
		}
		ft_exec_inst(lista, listb, "pa", listopt);
	}
}
