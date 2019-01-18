/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:26:37 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 16:15:47 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_print_char(va_list ap, t_flag flag)
{
	char	var;
	int		nb;

	nb = 1;
	var = va_arg(ap, int);
	if (flag.sign != 3)
		flag_space_str(flag, &nb);
	ft_putchar(var);
	var = (char)var;
	if (flag.sign == 3)
		flag_space_neg(flag.space, nb, &nb);
	return (nb);
}
