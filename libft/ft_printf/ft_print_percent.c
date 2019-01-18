/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:29:05 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:29:06 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_percent(t_flag flag, const char *f, int t)
{
	int nb;

	nb = 1;
	if (flag.sign != 3)
		flag_space_percent(f, nb, t, &nb);
	ft_putchar('%');
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
