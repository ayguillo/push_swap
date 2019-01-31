/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:15:34 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/31 15:07:33 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		ft_med(t_pslist *list, int len)
{
	int			i;
	t_pslist	*tmp;
	int			tab[len];
	int			tmp2;

	i = -1;
	tmp = list;
	while (++i < len)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
	}
	i = 0;
	while (i < len)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp2 = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp2;
			i = 0;
		}
		else
			i++;
	}
	i = -1;
	if (len >= 2)
		return (tab[(len / 2)]);
	return (tab[0]);
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
