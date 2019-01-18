/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:31:43 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/18 12:29:54 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	int			n;
	t_pslist	*a;
	char		*line;
	t_pslist	*b;

	n = 1;
	line = NULL;
	if (ac >= 1)
	{
		while (av[n])
		{
			a = ft_addr(a, ft_atoi(av[n]));
			n++;
		}
		printf("avant exec \n a\n");
		ft_printlist_nb(a);
		ft_s(&a, &b);
		ft_p(&a, &b);
		printf("apres exec \n a\n");
		ft_printlist_nb(a);
		printf(" b\n");
		ft_printlist_nb(b);
	}
	return (0);
}
