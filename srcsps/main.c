/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:34:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/23 18:51:21 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_init(t_pslist **lista, t_pslist **listb)
{
	*lista = NULL;
	*listb = NULL;
}

int				main(int ac, char **av)
{
	int			n;
	t_pslist	*lista;
	t_pslist	*listb;

	n = 0;
	ft_init(&lista, &listb);
	if (ac < 1)
		return (0);
	while (av[++n])
	{
		if (ft_parsing(av[n], &lista, &listb) > 0 ||
				!(lista = ft_addr(lista, ft_atoi(av[n]))))
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	if (ft_verif(lista) == 1)
	{
		ft_freelist(&lista, &listb);
		return (0);
	}
	ft_printlist_nb(lista);
	ft_shortsort(&lista, &listb);
	ft_printlist_nb(lista);
}