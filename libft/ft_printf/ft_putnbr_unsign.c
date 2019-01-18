/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsign.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:38:56 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:38:57 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_unsign(unsigned long long nb, int base)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('a' + (nb - 10));
		return ;
	}
	ft_putnbr_unsign(nb / base, base);
	ft_putnbr_unsign(nb % base, base);
}

void	ft_putnbr_unsign_maj(unsigned long long nb, int base)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('A' + (nb - 10));
		return ;
	}
	ft_putnbr_unsign_maj(nb / base, base);
	ft_putnbr_unsign_maj(nb % base, base);
}
