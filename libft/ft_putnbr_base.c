/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:54:50 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:27:46 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnbr_base(long long nb, int base)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < (long long)base)
	{
		if (nb < 10)
			ft_putchar('0' + nb);
		else
			ft_putchar('a' + (nb - 10));
		return ;
	}
	ft_putnbr_base(nb / base, base);
	ft_putnbr_base(nb % base, base);
}
