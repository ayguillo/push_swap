/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:09:19 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/24 17:13:47 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static char		*ft_realloc(char *ptr, size_t new_size)
{
	char	*new;
	size_t	old_size;
	size_t	i;

	if (ptr != NULL)
	{
		old_size = ft_strlen(ptr);
		new_size = new_size + old_size;
	}
	i = 0;
	if (!(new = (char *)malloc(sizeof(new) * (new_size + 1))))
		return (NULL);
	if (ptr != NULL)
	{
		while ((i <= old_size))
		{
			new[i] = ptr[i];
			i++;
		}
		ft_strdel(&ptr);
	}
	while (i <= new_size)
		new[i++] = '\0';
	return (new);
}

static int		ft_buffer(char **buff, char **line)
{
	size_t	i;
	char	*end;
	char	*tmp;

	i = 0;
	if (*buff == NULL || ft_strcmp(*buff, "") == 0)
	{
		*line = NULL;
		return (-1);
	}
	if ((end = ft_strchr(*buff, '\n')))
	{
		*line = ft_strcdup(*buff, '\n');
		tmp = ft_strdup(ft_memmove(*buff, &end[1], ft_strlen(&end[1])));
		tmp[ft_strlen(&end[1])] = '\0';
		*buff = ft_strdup(tmp);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strcdup(*buff, '\0');
	ft_strdel(buff);
	return (0);
}

static int		ft_read(const int fd, char **buff, char **str)
{
	int		ret;
	char	*end;
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) && ret >= 0)
	{
		tmp[ret] = '\0';
		*str = ft_realloc(*str, ret);
		*str = ft_strncat(*str, tmp, ret);
		if ((end = ft_strchr(*str, '\n')))
		{
			tmp = (char *)ft_memmove(tmp, end + 1, ft_strlen(end + 1));
			tmp[ft_strlen(end + 1)] = '\0';
			*buff = ft_strcdup(tmp, '\0');
			ft_strdel(&tmp);
			return (ret);
		}
		if (ret < BUFF_SIZE)
			return (ret);
	}
	return (ret);
}

static t_list	*ft_multiple_fd(t_list **lst, size_t fd)
{
	t_list *head;

	if (!(*lst))
	{
		*lst = ft_lstnew(NULL, 0);
		(*lst)->content_size = fd;
		return (*lst);
	}
	head = *lst;
	while (head)
	{
		if (head->content_size == fd)
			return (head);
		head = head->next;
	}
	head = ft_lstnew(NULL, 0);
	head->content_size = fd;
	ft_lstadd(lst, head);
	return (head);
}

int				ft_gnl(const int fd, char **line)
{
	int				ret;
	char			*str;
	static t_list	*lst;
	t_list			*head;

	str = NULL;
	ret = 0;
	head = ft_multiple_fd(&lst, (size_t)fd);
	if (line == NULL)
		return (-1);
	if (ft_buffer((char **)&head->content, line) == 1)
		return (1);
	ret = ft_read(fd, (char **)&head->content, &str);
	if (ret == -1 || (ret == 0 && *line == NULL && str == NULL))
	{
		ft_strdel((char **)&head->content);
		return (ret);
	}
	if (str != NULL)
	{
		*line = ft_realloc(*line, ft_strclen(str, '\n'));
		*line = ft_strncat(*line, ft_strcdup(str, '\n'), ft_strclen(str, '\n'));
	}
	ft_strdel(&str);
	return (1);
}
