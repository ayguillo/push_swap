/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_spaceprintnumb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:50:07 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:50:24 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		get_var(t_flag flag, int *var, va_list ap)
{
	*var = va_arg(ap, int);
	if (flag.hl == 2)
		*var = (char)(*var);
	else if (flag.hl == 1)
		*var = (short)(*var);
}

int			ender(t_flag flag, int *nb)
{
	if (flag.sign == 3 || flag.sign == 4)
		flag_space_neg(flag.space, *nb, nb);
	return (*nb);
}

void		gain_space_mid(int var, t_flag flag, char *a, int *size)
{
	if (var < 0 && flag.precis != -10)
	{
		(*size)--;
		*a = 1;
	}
}

void		gain_space_mid1(t_flag flag, int *nb, int var)
{
	if (flag.sign != 3 && flag.sign != 4)
		flag_space(flag, nb);
	print_flag_plus_space(flag, var, nb);
}
