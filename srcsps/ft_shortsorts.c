/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortsorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:57:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 14:00:58 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_end(t_pslist **lista, t_pslist **listb, int min, t_opti **listop)
{
	while ((*lista)->content != min)
		ft_exec_inst(lista, listb, "ra\n", listop);
	if (ft_verif(*lista) != 1)
	{
		ft_exec_inst(lista, listb, "pb\n", listop);
		ft_exec_inst(lista, listb, "sa\n", listop);
		ft_exec_inst(lista, listb, "pa\n", listop);
	}
}

void		ft_shortsort(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int			max;
	int			min;
	int			i;
	int			j;

	i = 0;
	j = 0;
	min = ft_min(*lista, &i);
	max = ft_max(*lista, &j);
	if (ft_verif(*lista) == 1)
		return ;
	if (j > ft_pslstlen(*lista) / 2)
		ft_exec_inst(lista, listb, "sa\n", listopt);
	else if (i > ft_pslstlen(*lista) / 2)
	{
		if ((*lista)->content < (*lista)->next->content)
			ft_exec_inst(lista, listb, "rra\n", listopt);
		else
		{
			ft_exec_inst(lista, listb, "sa\n", listopt);
			ft_exec_inst(lista, listb, "rra\n", listopt);
		}
	}
	else
		ft_end(lista, listb, min, listopt);
}
