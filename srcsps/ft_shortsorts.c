/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortsorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 12:57:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/23 19:09:37 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_shortsort(t_pslist **lista, t_pslist **listb)
{
	t_pslist	*tmp;
	int			min;
	int			max;
	int			i;

	tmp = *lista;
	min = (*lista)->content;
	max = (*lista)->content;
	if (ft_pslstlen(*lista) > 3)
		return ;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	tmp = *lista;
	i = 0;
	while (tmp && tmp->content != min)
	{
		i++;
		tmp = tmp->next;
	}
	if (i == 2)
	{
		if ((*lista)->content > (*lista)->next->content)
			ft_exec_inst(lista, listb, "sa");
		ft_exec_inst(lista, listb, "rra");
	}
}

int		ft_med(t_pslist *list)
{
	t_pslist	*tmp;
	t_pslist	*tmp1;
	int			med;
	int			medlen;
	int			i;

	tmp = list;
	while (tmp)
	{
		med = tmp->content;
		medlen = ft_pslstlen(list) / 2;
		tmp1 = list;
		i = 1;
		while (tmp1)
		{
			if (tmp1->content < med)
				medlen--;
			tmp1 = tmp1->next;
		}
		if (medlen == 0)
			break ;
		tmp = tmp->next;
	}
	return (med);
}
