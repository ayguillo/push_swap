/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:10:22 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 13:41:59 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		ft_strdel(&tmp->str);
		free(tmp);
		tmp = NULL;
	}
}

static void	ft_options(char **av, int *j, int *n)
{
	if (!(ft_strcmp(av[1], "-v")))
	{
		*j = -1;
		*n = 1;
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
	if (ac < 2)
		return (0);
	ft_options(av, &j, &n);
	while (av[++n])
		if (ft_parsing(av[n], &lista, &listb) > 0 ||
				!(lista = ft_addr(lista, ft_atoi(av[n]))))
		{
			ft_strdel(&line);
			ft_putstr("Error\n");
			return (-1);
		}
	ft_checker(line, &lista, &listb, &j);
	if (j > 0)
		return (-1);
	ft_verif(lista) == 1 ? ft_putstr("OK\n") : ft_putstr("KO\n");
	ft_freelist(&lista, &listb);
	return (0);
}
