/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 11:43:13 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/10 11:43:14 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		get_precision(const char *f, int t, int *ret)
{
	int		size;

	size = flag_precision(f, t);
	if (size == 0 || size == -5)
		(*ret)--;
	return (size);
}

int		get_precision2(const char *f, int t)
{
	int		size;

	size = flag_precision(f, t);
	return (size);
}
