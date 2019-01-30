/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:31:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/29 09:43:36 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_insertsort(t_pslist **lista, t_pslist **listb)
{
	int			min;
	int			place;
	t_pslist	*tmp;

	while (*lista)
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
		ft_exec_inst(lista, listb, "pa");
}
