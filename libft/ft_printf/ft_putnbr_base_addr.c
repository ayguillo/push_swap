/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_addr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:38:03 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:38:04 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_base_addr(unsigned long long nb, int base, int *ret)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
		{
			ft_putchar('0' + nb);
			(*ret)++;
		}
		else
		{
			ft_putchar('a' + (nb - 10));
			(*ret)++;
		}
		return ;
	}
	ft_putnbr_base_addr(nb / base, base, ret);
	ft_putnbr_base_addr(nb % base, base, ret);
}
