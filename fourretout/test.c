/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 10:25:38 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/18 13:43:01 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

t_check	*ft_add_check(char *str, void (*ft_ptr_instr)(t_pslist **, t_pslist **),
		t_check *list)
{
	t_check		*nvel;
	t_check		*tmp;

	if (!(nvel = malloc(sizeof(t_pslist))))
		return (NULL);
	if (!(nvel->str = malloc(sizeof(char*) * 3)))
		return (NULL);
	nvel->str = str;
	nvel->ft_instruction1 = ft_ptr_instr;
	nvel->next = NULL;
	if (!(list))
		return (nvel);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nvel;
	if (nvel)
		free(nvel->str);
	return (list);
}

int		main(int ac, char **av)
{
	t_check	*head;
	t_pslist	*lista;
	t_pslist	*listb;
	int		n;
	void	(*ft_ptr_instr)(t_pslist **, t_pslist **);

	ft_ptr_instr = ft_s;
	if (ac >= 1)
	{
		n = 1;
		while (av[n])
		{
			lista = ft_addr(lista, ft_atoi(av[n]));
			listb = ft_addr(listb, ft_atoi(av[n]));
			n++;
		}
	}
	head = ft_add_check("sb", ft_s, head);
	head->ft_instruction1(&listb, &lista);
	head = head->next;
	ft_printlist_nb(listb);
}
