/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:19:20 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 15:19:23 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		n;

	n = 0;
	while (s1[n])
		n++;
	if (!(dup = (char*)malloc(n + 1)))
		return (NULL);
	n = 0;
	while (s1[n])
	{
		dup[n] = s1[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
