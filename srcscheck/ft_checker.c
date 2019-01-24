/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:56:25 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/24 17:18:40 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_check	*ft_add_check(char *str,
		void (*ft_ptr_instr)(t_pslist **, t_pslist **), t_check *list)
{
	t_check		*nvel;
	t_check		*tmp;

	if (!(nvel = malloc(sizeof(t_check))))
		return (NULL);
	if (!(nvel->str = ft_strdup(str)))
	{
		free(nvel);
		return (NULL);
	}
	nvel->ft_instruction1 = ft_ptr_instr;
	nvel->next = NULL;
	if (!list)
		return (nvel);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nvel;
	return (list);
}

static t_check	*ft_init_checker(void)
{
	t_check		*checker;

	checker = ft_add_check("sa", ft_s, NULL);
	checker = ft_add_check("sb", ft_s, checker);
	checker = ft_add_check("ss", ft_s, checker);
	checker = ft_add_check("pa", ft_p, checker);
	checker = ft_add_check("pb", ft_p, checker);
	checker = ft_add_check("ra", ft_r, checker);
	checker = ft_add_check("rb", ft_r, checker);
	checker = ft_add_check("rr", ft_r, checker);
	checker = ft_add_check("rra", ft_rr, checker);
	checker = ft_add_check("rrb", ft_rr, checker);
	checker = ft_add_check("rrr", ft_rr, checker);
	return (checker);
}

static t_check	*ft_dispatcher(t_check *checker, t_pslist **lista,
		t_pslist **listb, char *line)
{
	if (!ft_strcmp(line, "sa") || !ft_strcmp(line, "pb") ||
			!ft_strcmp(line, "ra") || !ft_strcmp(line, "rra"))
		checker->ft_instruction1(lista, listb);
	else if (!ft_strcmp(line, "sb") || !ft_strcmp(line, "pa") ||
			!ft_strcmp(line, "rb") || !ft_strcmp(line, "rrb"))
		checker->ft_instruction1(listb, lista);
	else if (!ft_strcmp(line, "ss") || !ft_strcmp(line, "rr") ||
			!ft_strcmp(line, "rrr"))
	{
		checker->ft_instruction1(lista, listb);
		checker->ft_instruction1(listb, lista);
	}
	else
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	return (checker);
}

void			ft_checker(char *line, t_pslist **lista, t_pslist **listb,
		int *err)
{
	int			n;
	t_check		*checker;
	t_check		*tmp;

	checker = ft_init_checker();
	tmp = checker;
	while ((n = ft_gnl(0, &line)))
	{
		while (ft_strcmp(line, checker->str) && checker->next)
			checker = checker->next;
		if (!(ft_dispatcher(checker, lista, listb, line)))
		{
			ft_strdel(&line);
			ft_delchecklist(&checker);
			ft_freelist(lista, listb);
			(*err)++;
			return ;
		}
		checker = tmp;
		ft_strdel(&line);
	}
	if (line)
		ft_strdel(&line);
	ft_delchecklist(&checker);
}
