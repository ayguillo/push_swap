/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:24:39 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 16:15:51 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		get_good_c(t_flag flag, int size)
{
	char c;

	c = ' ';
	if (flag.zero == 1)
		c = '0';
	if (flag.precis != -10)
		if (size >= flag.precis || flag.space > flag.precis)
			c = ' ';
	return (c);
}

static void		print_space_percent(char c, int *j, int *ret)
{
	ft_putchar(c);
	(*j)++;
	(*ret)++;
}

void			flag_space_percent(const char *f, int nb, int t, int *ret)
{
	int		k;
	int		j;
	char	c;

	j = 0;
	c = ' ';
	while ((f[t] < '0' || f[t] > '9') && f[t] != 'c' && f[t] != 's'
			&& f[t] != 'p' && f[t] != 'd' && f[t] != 'i' && f[t] != 'o'
			&& f[t] != 'u' && f[t] != 'x' && f[t] != 'X' && f[t] != 'f'
			&& f[t] != '%' && f[t] != '\0')
	{
		if (f[t] == '-' || f[t] == '.')
			break ;
		t++;
	}
	if (f[t] == '0')
		c = '0';
	k = ft_atoi(&f[t]);
	if (k > 0)
		while (j < k - nb)
			print_space_percent(c, &j, ret);
}

void			flag_space_str(t_flag flag, int *ret)
{
	int		j;
	char	c;
	int		size;

	size = *ret;
	j = 0;
	c = ' ';
	if (flag.zero == 1)
		c = '0';
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.zero == 0 && (flag.sign != 0))
		size++;
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
		{
			ft_putchar(c);
			j++;
			(*ret)++;
		}
}

void			flag_space(t_flag flag, int *ret)
{
	int		j;
	char	c;
	int		size;
	int		tmp;

	size = *ret;
	tmp = flag.precis;
	j = 0;
	c = get_good_c(flag, size);
	if (flag.precis <= size)
		flag.precis = 0;
	else
		flag.precis = flag.precis - size;
	if (flag.neg == 0 && flag.sign != 0 && flag.space > tmp && tmp >= 0)
		size++;
	if (flag.neg == 1 && (flag.zero == 1 || flag.sign != 0 || tmp >= size)
			&& flag.space > tmp && tmp >= 0)
		size++;
	if (flag.space > 0)
		while (j < flag.space - size - flag.precis)
		{
			ft_putchar(c);
			(j)++;
			(*ret)++;
		}
}
