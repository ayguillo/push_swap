/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_space_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:43:26 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 15:10:43 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		get_space_after_hash(const char *f, int t, int k)
{
	int k1;

	while (f[t] != '#' && f[t] != '\0')
	{
		if (!(f[t] >= '0' && f[t] <= '9'))
			break ;
		t++;
	}
	while ((f[t] < '0' || f[t] > '9') && f[t] != 'c' && f[t] != 's'
			&& f[t] != 'p' && f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0' && f[t] != '.')
		t++;
	while (f[t] == '0')
		t++;
	while (f[t] == '+' || f[t] == ' ')
		t++;
	k1 = ft_atoi(&f[t]);
	if (k1 == 0)
		k1 = k;
	return (k1);
}

int				get_space_number(const char *f, int t, t_flag flag)
{
	int		k;

	while ((f[t] < '0' || f[t] > '9') && f[t] != 'c' && f[t] != 's'
			&& f[t] != 'p' && f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0' && f[t] != '.')
		t++;
	while (f[t] == '0')
		t++;
	while (f[t] == '+' || f[t] == ' ')
		t++;
	k = ft_atoi(&f[t]);
	if (flag.hash == 1)
		k = get_space_after_hash(f, t, k);
	return (k);
}
