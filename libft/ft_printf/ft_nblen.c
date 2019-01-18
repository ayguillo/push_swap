/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:50:54 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:56:47 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_nblen(long long nb, int base, int *sum)
{
	if (nb < 0)
	{
		nb = -nb;
		(*sum)++;
	}
	if (nb < (long long)base)
	{
		if (nb < 10)
			(*sum)++;
		else
			(*sum)++;
		return ;
	}
	ft_nblen(nb / base, base, sum);
	ft_nblen(nb % base, base, sum);
}

static void	get_neg(long long *nb, int *sum)
{
	if (*nb < 0)
	{
		(*sum)++;
		*nb = -(*nb);
	}
}

void		ft_nblen_double(long long nb, int *sum)
{
	int		x;
	int		i;
	double	y;
	double	tmp;

	i = 0;
	get_neg(&nb, sum);
	x = (unsigned long long)nb;
	ft_nblen(x, 10, sum);
	(*sum)++;
	y = (nb - x);
	tmp = y;
	tmp = tmp * 10;
	while ((int)tmp == 0 && i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
	while (i < 6)
	{
		(*sum)++;
		tmp = tmp * 10;
		i++;
	}
}
