/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:16:52 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/28 16:16:05 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_partition(t_pslist **lista, t_pslist **listb, int len, int med)
{
	int		countra;

	countra = 0;
	while (len > 0)
	{
		if ((*lista)->content < med)
			ft_exec_inst(lista, listb, "pb");
		else
		{
			countra++;
			ft_exec_inst(lista, listb, "ra");
		}
		len--;
	}
	return (countra);
}


void		ft_quicksort(t_pslist **lista, t_pslist **listb, int len)
{
	int		pivot;
	int		i;

	i = -1;
	if (len < 2)
		return ;
	pivot = ft_med(*lista, len);
	printf("pivot == %i\nlen === %i\n", pivot, len);
	pivot = ft_partition(lista, listb, len, pivot);
	while (++i < pivot)
	{
		ft_exec_inst(lista, listb, "rra");
	}
	ft_quicksort(lista, listb, pivot);
	i = len - pivot;
	while (i > 0)
	{
		ft_exec_inst(lista, listb, "pa");
		i--;
	}
	ft_quicksort(lista, listb, len - pivot);
}
