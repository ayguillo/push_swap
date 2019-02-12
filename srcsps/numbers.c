/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:34 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/12 14:54:32 by ayguillo         ###   ########.fr       */
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
