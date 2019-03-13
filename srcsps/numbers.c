/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:34 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 14:18:35 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_min(t_pslist *list, int *i)
{
	int			min;
	t_pslist	*tmp;

	tmp = list;
	min = list->content;
	while (list)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	while (tmp->content != min)
	{
		(*i)++;
		tmp = tmp->next;
	}
	return (min);
}

int		ft_max(t_pslist *list, int *j)
{
	int			max;
	t_pslist	*tmp;

	tmp = list;
	max = list->content;
	while (list)
	{
		if (list->content > max)
			max = list->content;
		list = list->next;
	}
	while (tmp->content != max)
	{
		(*j)++;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_pslstlen(t_pslist *list)
{
	int		len;

	len = 0;
	while (list)
	{
		list = list->next;
		len++;
	}
	return (len);
}

void	ft_loop(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	int contenta;
	int contentb;
	int	i;

	contentb = ft_best(*lista, *listb, ft_pslstlen(*listb));
	i = ft_go(*listb, contentb);
	if (i <= ft_pslstlen(*listb) / 2)
		while ((*listb)->content != contentb)
			ft_exec_inst(lista, listb, "rb\n", listopt);
	else
		while ((*listb)->content != contentb)
			ft_exec_inst(lista, listb, "rrb\n", listopt);
	contenta = ft_best_waya(*lista, contentb);
	i = ft_go(*lista, contenta);
	if (i <= ft_pslstlen(*lista) / 2)
		while ((*lista)->content != contenta)
			ft_exec_inst(lista, listb, "ra\n", listopt);
	else
		while ((*lista)->content != contenta)
			ft_exec_inst(lista, listb, "rra\n", listopt);
}
