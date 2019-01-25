/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:34 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/25 18:46:56 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_med(t_pslist *list, int len)
{
	t_pslist	*tmp;
	t_pslist	*tmp1;
	int			med;
	int			medlen;
	int			i;
	int			j;

	tmp = list;
	i = -1;
	while (tmp && ++i < len)
	{
		med = tmp->content;
		medlen = ((len / 2) - 1);
		tmp1 = list;
		j = -1;
		while (tmp1 && j < len)
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
