/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:34:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/13 14:32:38 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init(t_pslist **lista, t_pslist **listb, t_opti **listopt,
		int *n)
{
	*lista = NULL;
	*listb = NULL;
	*listopt = NULL;
	*n = 0;
}

void		ft_delopti(t_opti *listopt)
{
	t_opti	*tmp;

	while (listopt)
	{
		tmp = listopt;
		listopt = listopt->next;
		ft_strdel(&tmp->str);
		free(tmp);
		tmp = NULL;
	}
}

static void	ft_affopti(t_opti *listopt)
{
	while (listopt)
	{
		ft_putstr(listopt->str);
		listopt = listopt->next;
	}
}

static int	ft_parsok(char **av, t_pslist **lista, t_pslist **listb, int n)
{
	if (ft_parsing(av[n], lista, listb) > 0 ||
				!(*lista = ft_addr(*lista, ft_atoi(av[n]))))
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}

int			main(int ac, char **av)
{
	int			n;
	t_pslist	*lista;
	t_pslist	*listb;
	t_opti		*listopt;

	ft_init(&lista, &listb, &listopt, &n);
	if (ac < 2)
		return (0);
	while (av[++n])
		if (ft_parsok(av, &lista, &listb, n) == -1)
			return (-1);
	if (ft_verif(lista))
	{
		ft_freelist(&lista, &listb);
		return (0);
	}
	ft_insertsort(&lista, &listb, &listopt);
	listopt = ft_optinst(listopt);
	ft_affopti(listopt);
	ft_freelist(&lista, &listb);
	ft_delopti(listopt);
	return (0);
}
