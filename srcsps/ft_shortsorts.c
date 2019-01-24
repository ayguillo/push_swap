/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortsorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:57:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/24 14:18:14 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_end(t_pslist **lista, t_pslist **listb, int min)
{
	while ((*lista)->content != min)
		ft_exec_inst(lista, listb, "ra");
	if (ft_verif(*lista) != 1)
	{
		ft_exec_inst(lista, listb, "pb");
		ft_exec_inst(lista, listb, "sa");
		ft_exec_inst(lista, listb, "pa");
	}
}

void		ft_shortsort(t_pslist **lista, t_pslist **listb)
{
	t_pslist	*tmp;
	int			max;
	int			min;
	int			i;
	int			j;

	i = 0;
	j = 0;
	min = ft_min(*lista, &i);
	max = ft_max(*lista, &j);
	tmp = *lista;
	if (j > ft_pslstlen(*lista) / 2)
		ft_exec_inst(lista, listb, "sa");
	else if (i > ft_pslstlen(*lista) / 2)
	{
		if ((*lista)->content < (*lista)->next->content)
			ft_exec_inst(lista, listb, "rra");
		else
		{
			ft_exec_inst(lista, listb, "sa");
			ft_exec_inst(lista, listb, "rra");
		}
	}
	else
		ft_end(lista, listb, min);
}
