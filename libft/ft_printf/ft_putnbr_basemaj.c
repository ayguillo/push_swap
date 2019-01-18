/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_basemaj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:38:22 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:38:24 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_basemaj(long long nb, int base)
{
	if (nb < (long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('A' + (nb - 10));
		return ;
	}
	ft_putnbr_basemaj(nb / base, base);
	ft_putnbr_basemaj(nb % base, base);
}
