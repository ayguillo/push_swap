/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/01 19:10:21 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
 ** count = tab[0]
 ** countmin = tab[1]
 ** content = tab[2]
 ** controlea = tab[3]
 ** controleb = tab[4]
*/

static int	ft_count(t_pslist *lista, t_pslist *listb, int *waya, int *wayb)
{
	int tab[5];
	t_pslist	*tmp;

	tab[0] = 0;
	tab[1] = 2147483647;
	tab[4] = 0;
	while (listb)
	{
		tmp = lista;
		tab[3] = 0;
		while (lista)
		{
			if (lista->content < listb->content &&
					lista->next->content > listb->content)
				break;
			lista = lista->next;
			tab[3]++;
			tab[0]++;
			if (tab[3] > ft_pslstlen(lista) / 2)
				tab[0] = tab[0] - ft_pslstlen(lista) / 2;
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

void		ft_insertsort(t_pslist **lista, t_pslist **listb)
{
	int			waya;
	int			wayb;
	int			count;
	//	int			min;
	//	int			place;
	//	t_pslist	*tmp

	waya = 0;
	wayb = 0;
	while (ft_pslstlen(*lista) > 3)
		ft_exec_inst(lista, listb, "pb");
	ft_shortsort(lista, listb);
	count = ft_count(*lista, *listb, &waya, &wayb);
	while ((*listb)->content != count) 
	{
		if (wayb == 1 && waya == 1)
			ft_exec_inst(lista, listb, "rr");
		else if (wayb == 0 && waya == 0)
			ft_exec_inst(lista, listb, "rrr");
	}
	/*while (*lista)
	  {
	  place = 0;
	  min = ft_min(*lista, &place);
	  tmp = *lista;
	  while ((*lista)->content != min)
	  {
	  if (place > ft_pslstlen(*lista) / 2)
	  ft_exec_inst(lista, listb, "rra");
	  else
	  ft_exec_inst(lista, listb, "ra");
	  }
	  if (ft_verif(*lista) == 1)
	  break;
	  ft_exec_inst(lista, listb, "pb");
	  }
	  while (*listb)
	  ft_exec_inst(lista, listb, "pa");*/
}
