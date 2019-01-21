/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:41:19 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 13:33:57 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char	*dup;
	size_t	n;

	n = 0;
	while (s1[n] && n < size)
		n++;
	if (!(dup = (char*)malloc(sizeof(*dup) * (n + 1))))
		return (0);
	n = 0;
	while (n < size)
	{
		dup[n] = s1[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
