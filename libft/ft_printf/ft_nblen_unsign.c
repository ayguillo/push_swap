/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen_unsign.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:26:24 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:26:26 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_nblen_unsign(unsigned long long nb, int base, int *ret)
{
	if (nb < (unsigned long long)base)
	{
		if (nb < 10)
			(*ret)++;
		else
			(*ret)++;
		return ;
	}
	ft_nblen_unsign(nb / base, base, ret);
	ft_nblen_unsign(nb % base, base, ret);
}
