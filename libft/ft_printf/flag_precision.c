/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:24:22 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 15:54:20 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ending(char *flag, int k, int *size)
{
	flag[k] = '\0';
	*size = ft_atoi(flag);
	if (k == 0)
		*size = -5;
	free(flag);
}

static void		gain_space(const char *f, char **flag, int *t, int *k)
{
	while (f[*t] >= '0' && f[*t] <= '9')
	{
		(*flag)[*k] = f[*t];
		(*k)++;
		(*t)++;
	}
}

int				flag_precision(const char *f, int t)
{
	char	*flag;
	int		k;
	int		size;

	k = 0;
	increment(f, &k);
	if (!(flag = (char*)malloc(sizeof(*flag) * (k + 1))))
		return (-1);
	k = 0;
	while (f[t] != '.' && f[t] != 'c' && f[t] != 's' && f[t] != 'p'
			&& f[t] != 'd' && f[t] != 'i' && f[t] != 'o' && f[t] != 'u'
			&& f[t] != 'x' && f[t] != 'X' && f[t] != 'f' && f[t] != '%')
		t++;
	if (f[t] != '.')
	{
		free(flag);
		return (-10);
	}
	t++;
	gain_space(f, &flag, &t, &k);
	ending(flag, k, &size);
	return (size);
}

void			flag_precision_nb(t_flag flag, int nb, int *ret)
{
	int		len;
	int		tmp;
	char	*str;

	len = 0;
	while (flag.precis > nb)
	{
		flag.precis--;
		len++;
		(*ret)++;
	}
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return ;
	tmp = len;
	while (len >= 0)
		str[len--] = '0';
	write(1, str, tmp);
	free(str);
}
