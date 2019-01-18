/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:30:16 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 15:03:29 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		starter(int *i, int *sum, int *b)
{
	*i = 0;
	*sum = 0;
	*b = -5;
}

static void		increase_nb(const char *format, int *i, int *sum, int nb)
{
	increment(format, i);
	(*sum) += nb;
	(*i)++;
}

static void		get_cont(const char *format, int *i, int *sum)
{
	int		len;
	int		tmp;

	len = 0;
	tmp = *i;
	while (format[*i] && format[*i] != '%')
	{
		(*i)++;
		(*sum)++;
		len++;
	}
	write(1, &format[tmp], len);
}

static void		get_b_neg(int *b, int *sum)
{
	flag_space_neg_print_error(*b, sum);
	*b = -5;
}

int				ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		nb;
	int		sum;
	int		b;

	va_start(ap, format);
	starter(&i, &sum, &b);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if ((nb = dispatcher(ap, i, format)) != -1)
				increase_nb(format, &i, &sum, nb);
			else
				increment_error(format, &i, &b);
		}
		else
			get_cont(format, &i, &sum);
		if (b > 0)
			get_b_neg(&b, &sum);
	}
	va_end(ap);
	return (sum);
}
