/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:55:55 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/22 20:05:35 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_freelist(t_pslist **lista, t_pslist **listb)
{
	if (*lista || lista)
		ft_delallst(lista);
	if (*listb || listb)
		ft_delallst(listb);
}

int		ft_verif(t_pslist *list)
{
	int		tmp;

	if (!list || list->next == NULL)
		return (1);
	while (list->next)
	{
		tmp = list->content;
		list = list->next;
		if (tmp > list->content)
			return (0);
	}
	return (1);
}

int		ft_parsing(char *str, t_pslist **lista, t_pslist **listb)
{
	int	re;
	int	n;
	int	sign;

	n = -1;
	re = 0;
	sign = 0;
	while (str[++n])
	{
		if ((str[0] == '-' || str[0] == '+') && sign == 0)
		{
			n++;
			sign++;
		}
		if (!ft_isdigit(str[n]) || n > 11)
			re++;
	}
	if (re > 0 || (ft_atol(str)) > 2147483647 || ((ft_atol(str))) < -2147483648)
		re++;
	if (re > 0)
		ft_freelist(lista, listb);
	return (re);
}
