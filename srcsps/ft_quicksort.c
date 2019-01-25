/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:16:52 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/25 18:46:40 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*static int	ft_odd(int len)
  {
  return((len % 2 == 0) ? 1 : 0);
  }*/

static int	ft_partition(t_pslist **lista, t_pslist **listb, int len, int med)
{
	int		countpb;
	int		countra;

	if (len == 0)
		return (0);
	countpb = 0;
	countra = 0;
	while (countpb < len / 2)
	{
		if ((*lista)->content < med)
		{
			ft_exec_inst(lista, listb, "pb");
			countpb++;
		}
		else
		{
			ft_exec_inst(lista, listb, "ra");
			countra++;
		}
	}
	return (countra);
}

void		ft_quicksort(t_pslist **lista, t_pslist **listb, int len)
{
	int		pivot;
	int		i;

	i = 0;
	if (len < 2)
		return ;
	pivot = ft_med(*lista, len);
	pivot = ft_partition(lista, listb, len, pivot);
	while (i < pivot)
	{
		ft_exec_inst(lista, listb, "rra");
		i++;
	}
	ft_quicksort(lista, listb, pivot);
	ft_printlist_nb(*lista);
	i = len - pivot;
	if ((*listb))
	{
		len = 0;
		while ((*listb))
		{
			len++;
			ft_exec_inst(lista, listb, "pa");
		}
	}
	ft_quicksort(lista, listb, len - pivot);
}
