/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 11:18:20 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 17:42:23 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcdup(const char *s1, char c)
{
	char	*dup;
	int		n;
	
	if (!s1)
		return (NULL);
	if (!(dup = (char*)malloc(sizeof(char) * (ft_strclen(s1, c) + 1))))
		return (0);
	n = 0;
	while (s1[n] && s1[n] != c)
	{
		dup[n] = s1[n];
		n++;
	}
	dup[n] = '\0';
	return (dup);
}
