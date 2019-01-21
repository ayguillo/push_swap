/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:10:22 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/21 15:32:39 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_delchecklist(t_check **list)
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

int		main(int ac, char **av)
{
	int			n;
	t_pslist	*lista;
	t_pslist	*listb;
	char		*line;

	n = 1;
	line = NULL;
	lista = NULL;
	listb = NULL;
	if (ac >= 1)
		while (av[n])
		{
			lista = ft_addr(lista, ft_atoi(av[n]));
			n++;
		}
	ft_checker(line, &lista, &listb);
	ft_verif(lista) == 1 ? ft_putstr("OK\n") : ft_putstr("KO\n");
	ft_delallst(&lista);
	ft_delallst(&listb);
	ft_strdel(&line);
	while (1);
	return (0);
}
