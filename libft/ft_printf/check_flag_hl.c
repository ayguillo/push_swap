/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag_hl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:22:53 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:23:03 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		gain_space(int *h, int *k)
{
	*h = 1;
	(*k)++;
}

static void		gain_space1(int *h, int k, int k1)
{
	if (*h != 3 && *h != 4)
		if (k == 2 || k1 == 2)
			*h = 2;
}

int				check_flag_hl(const char *f, int t)
{
	int	h;
	int	k;
	int	k1;

	h = 0;
	k = 0;
	k1 = 0;
	while (f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X')
	{
		if (f[t] == 'l' && f[t + 1] == 'l' && h < 4)
			h = 4;
		else if (f[t] == 'l' && h < 3)
			h = 3;
		else if (f[t] == 'h')
			gain_space(&h, &k);
		else if (f[t] == 'L')
			h = 5;
		if (f[t] == 'h' && f[t - 1] != 'h')
			k1++;
		t++;
	}
	gain_space1(&h, k, k1);
	return (h);
}
