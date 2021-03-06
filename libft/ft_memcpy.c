/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:17:26 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:24:48 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*ptr;
	char	*str;
	size_t	i;

	i = 0;
	ptr = (char*)dst;
	str = (char*)src;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	return (dst);
}
