/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:17:29 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 16:54:30 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	move(void **ptr)
{
	char	*tmp;
	char	*str;

	str = (char*)*ptr;
	tmp = ft_strdup(ft_strchr(str, '\n') + 1);
	free(*ptr);
	*ptr = tmp;
}

t_list	*get_actual_list(t_list **list, int fd)
{
	t_list	*tempo;

	tempo = *list;
	while (tempo)
	{
		if ((int)tempo->content_size == fd)
			return (tempo);
		tempo = tempo->next;
	}
	tempo = ft_lstnew(NULL, fd);
	tempo->content_size = fd;
	ft_lstadd(list, tempo);
	tempo = *list;
	return (tempo);
}

int		ft_gnl(const int fd, char **line)
{
	static t_list	*list;
	char			buff[BUFF_SIZE + 1];
	int				r;
	int				i;
	t_list			*actual;

	if (fd < 0 || !line || read(fd, buff, 0) < 0)
		return (-1);
	actual = get_actual_list(&list, fd);
	while ((r = read(fd, buff, BUFF_SIZE)))
	{
		buff[r] = '\0';
		i = ft_strlen(actual->content);
		if (!(actual->content = ft_realloc(actual->content, i, i + BUFF_SIZE)))
			return (-1);
		actual->content = ft_strcat(actual->content, buff);
		if (ft_strchr(actual->content, '\n'))
			break ;
	}
	if (r < BUFF_SIZE && !ft_strlen(actual->content))
		return (0);
	*line = ft_strcdup(actual->content, '\n');
	(ft_strchr(actual->content, '\n')) ?
		(move(&actual->content)) : ft_strclr(actual->content);
	return (1);
}
