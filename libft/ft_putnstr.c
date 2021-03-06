/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 17:11:20 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:28:22 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putnstr(char const *str, int size)
{
	int i;

	i = 0;
	while (str[i] != '\0' && i < size)
		i++;
	write(1, str, i);
}
