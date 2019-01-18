/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:23:34 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 14:19:19 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_hash(const char *f, int t)
{
	int b;

	b = 0;
	while (f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X'
			&& f[t] != 'f' && f[t] != '%' && f[t] != '\0')
	{
		if (f[t] == '#')
			b = 1;
		t++;
	}
	return (b);
}

void	flag_hashxmaj(t_flag flag)
{
	if (flag.hash == 1)
		write(1, "0X", 2);
}

void	flag_hashx(t_flag flag)
{
	if (flag.hash == 1)
		write(1, "0x", 2);
}

void	flag_hasho(t_flag flag)
{
	if (flag.hash == 1)
		write(1, "0", 1);
}

void	flag_hashf(t_flag flag)
{
	if (flag.hash == 1)
		write(1, ".", 1);
}
