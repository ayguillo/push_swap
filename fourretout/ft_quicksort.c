/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:16:52 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/01 16:37:50 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_partition(t_pslist **lista, t_pslist **listb, int len, int med)
{
	int		countra;
	int		tmp;

	countra = 0;
	tmp = len;
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
	if (ft_pslstlen(*lista) < 2)
		return ;
	i = len - pivot;
	while (i > 0)
	{
		ft_exec_inst(lista, listb, "pa");
		i--;
	}
	ft_quicksort(lista, listb, pivot);
	ft_quicksort(lista, listb, len);
}
