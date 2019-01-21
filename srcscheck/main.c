/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:10:22 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 18:58:57 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_freelist(t_pslist **lista, t_pslist **listb)
{
	ft_delallst(lista);
	ft_delallst(listb);
}

static int	ft_parsing(char *str, t_pslist **lista, t_pslist **listb)
{
	int		re;
	int		n;
	int		sign;

	n = -1;
	re = 0;
	sign = 0;
	while (str[++n])
	{
		if ((str[0] == '-' || str[0] == '+') && sign == 0)
		{
			n++;
			sign++;
		}
		if (!ft_isdigit(str[n]) || n > 11)
			re++;
	}
	if (re > 0 || (ft_atol(str)) > 2147483647 || ((ft_atol(str))) < -2147483648)
		re++;
	if (re > 0)
		ft_freelist(lista, listb);
	return (re);
}

static void	ft_init(t_pslist **lista, t_pslist **listb, char **line, int *j)
{
	*line = NULL;
	*lista = NULL;
	*listb = NULL;
	*j = 0;
}

void		ft_delchecklist(t_check **list)
{
	t_check		*tmp;
	t_check		*head;

	while (*list)
	{
		tmp = (*list)->next;
		head = *list;
		ft_strdel(&head->str);
		free(head);
		*list = tmp;
	}
}

int			main(int ac, char **av)
{
	int			n;
	int			j;
	t_pslist	*lista;
	t_pslist	*listb;
	char		*line;

	n = 0;
	ft_init(&lista, &listb, &line, &j);
	if (ac < 1)
		return (0);
	while (av[++n])
	{
		if (ft_parsing(av[n], &lista, &listb) > 0)
		{
			ft_putstr("Error\n");
			return (-1);
		}
		lista = ft_addr(lista, ft_atoi(av[n]));
	}
	ft_checker(line, &lista, &listb, &j);
	if (j > 0)
		return (-1);
	ft_verif(lista) == 1 ? ft_putstr("OK\n") : ft_putstr("KO\n");
	ft_freelist(&lista, &listb);
	return (0);
}
