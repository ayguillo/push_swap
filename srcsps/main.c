/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 19:34:49 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/05 16:50:53 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_init(t_pslist **lista, t_pslist **listb, t_opti **listopt)
{
	*lista = NULL;
	*listb = NULL;
	*listopt = NULL;
}

int				main(int ac, char **av)
{
	int			n;
	t_pslist	*lista;
	t_pslist	*listb;
	t_opti		*listopt;
	t_opti		*tmp;

	n = 0;
	ft_init(&lista, &listb, &listopt);
	if (ac < 1)
		return (0);
	while (av[++n])
		if (ft_parsing(av[n], &lista, &listb) > 0 ||
				!(lista = ft_addr(lista, ft_atoi(av[n]))))
		{
			ft_putstr("Error\n");
			return (-1);
		}
	printf("\x1b[32m Lista avant exec \n");
	ft_printlist_nb(lista);
	ft_insertsort(&lista, &listb, &listopt);
	tmp = listopt;
	//ft_optinst(&tmp);
	while (listopt)
	{
		printf("%s\n", listopt->str);
		listopt = listopt->next;
	}
	printf("\x1b[31mExec programme \x1b[0m\n");
	ft_printf("_________________a____________\n");
	ft_printlist_nb(lista);
	ft_printf("_________________b____________\n");
	ft_printlist_nb(listb);
	ft_freelist(&lista, &listb);
	return (0);
}
