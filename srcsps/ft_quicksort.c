/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 11:16:52 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/31 15:07:37 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_partition(t_pslist **lista, t_pslist **listb, int len, int med)
{
	int		countra;
	int		i;

	countra = 0;
	i = -1;
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
	if (countra < ft_pslstlen(*lista) / 2)
		while (++i < countra)
			ft_exec_inst(lista, listb, "rra");
	else
		while (++i < ft_pslstlen(*lista) - countra)
			ft_exec_inst(lista, listb, "ra");
	return (countra);
}

void		ft_quicksort(t_pslist **lista, t_pslist **listb, int len)
{
	int			part;
	int			i;
	t_pslist	*tmp;
	int			lenla;
	int			med;

	tmp = *lista;
	lenla = ft_pslstlen(tmp);
	if (len < 2 || lenla < 2)
		return ;
	med = ft_med(tmp, len);
	part = ft_partition(lista, listb, len, med);
	ft_quicksort(lista, listb, part);
	i = len - part;
	while (i > 0)
	{
		ft_exec_inst(lista, listb, "pa");
		i--;
	}
	ft_quicksort(lista, listb, len - part);
}
