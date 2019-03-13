/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:17:29 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 11:39:19 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	move(void **ptr)
{
	char	*str;
	char	*tmp;

	str = (char*)*ptr;
	tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	ft_strdel(&tmp);
	free(*ptr);
	*ptr = tmp;
}

int		ft_gnl(const int fd, char **line)
{
	char			buff[BUFF_SIZE + 1];
	static char		*str;
	int				r;
	int				i;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		i = ft_strlen(str);
		if (!(str = ft_realloc(str, i, i + BUFF_SIZE)))
			return (-1);
		str = ft_strcat(str, buff);
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(str))
		return (0);
	*line = ft_strcdup(str, '\n');
	(ft_strchr(str, '\n')) ?
		(move((void**)&str)) : ft_strdel(&str);
	return (1);
}
