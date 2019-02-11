/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:34:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 13:47:00 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_init(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	*lista = NULL;
	*listb = NULL;
	*listopt = NULL;
}

static void		ft_delopti(t_opti *listopt)
{
	t_opti	*tmp;

	while (listopt)
	{
		tmp = listopt;
		tmp = tmp->next;
		ft_strdel(&listopt->str);
		free(listopt);
		listopt = NULL;
	}
}

static void		ft_affinst(t_opti *listopt)
{
	while (listopt)
	{
		ft_putstr(listopt->str);
		listopt = listopt->next;
	}
}

int				main(int ac, char **av)
{
	int			n;
	t_pslist	*lista;
	t_pslist	*listb;
	t_opti		*listopt;
	
	n = 0;
	ft_init(&lista, &listb, &listopt);
	if (ac < 2)
		return (0);
	while (av[++n])
		if (ft_parsing(av[n], &lista, &listb) > 0 ||
				!(lista = ft_addr(lista, ft_atoi(av[n]))))
		{
			ft_putstr("Error\n");
			return (-1);
		}
	ft_insertsort(&lista, &listb, &listopt);
	listopt = ft_optinst(listopt);
	ft_affinst(listopt);
	ft_freelist(&lista, &listb);
	ft_delopti(listopt);
	return (0);
}
