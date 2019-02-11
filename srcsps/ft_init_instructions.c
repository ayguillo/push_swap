/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:54:55 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/11 16:01:05 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void				ft_delinst(t_instructions *list)
{
	t_instructions	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		ft_strdel(&tmp->str);
		free(tmp);
		tmp = NULL;
	}
}

static t_instructions	*ft_addinst(char *str,
		void (*ft_ptr_instr)(t_pslist **, t_pslist **), t_instructions *list)
{
	t_instructions	*nvel;
	t_instructions	*tmp;

	if (!(nvel = malloc(sizeof(t_instructions))))
		return (NULL);
	if (!(nvel->str = ft_strdup(str)))
	{
		ft_strdel(&(nvel)->str);
		free(nvel);
		return (NULL);
	}
	nvel->ft_instruction = ft_ptr_instr;
	nvel->next = NULL;
	if (!list)
		return (nvel);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nvel;
	return (list);
}

static t_instructions	*ft_init_inst(void)
{
	t_instructions	*inst;

	inst = NULL;
	inst = ft_addinst("sa\n", ft_s, NULL);
	inst = ft_addinst("sb\n", ft_s, inst);
	inst = ft_addinst("ss\n", ft_s, inst);
	inst = ft_addinst("pa\n", ft_p, inst);
	inst = ft_addinst("pb\n", ft_p, inst);
	inst = ft_addinst("ra\n", ft_r, inst);
	inst = ft_addinst("rb\n", ft_r, inst);
	inst = ft_addinst("rr\n", ft_r, inst);
	inst = ft_addinst("rra\n", ft_rr, inst);
	inst = ft_addinst("rrb\n", ft_rr, inst);
	inst = ft_addinst("rrr\n", ft_rr, inst);
	return (inst);
}

static t_instructions	*ft_dispatcher_inst(t_instructions *inst,
		t_pslist **lista, t_pslist **listb, char *str)
{
	while (ft_strcmp(inst->str, str) && inst)
		inst = inst->next;
	if (!ft_strcmp(str, "sa\n") || !ft_strcmp(str, "pb\n") ||
			!ft_strcmp(str, "ra\n") || !ft_strcmp(str, "rra\n"))
		inst->ft_instruction(lista, listb);
	else if (!ft_strcmp(str, "sb\n") || !ft_strcmp(str, "pa\n") ||
			!ft_strcmp(str, "rb\n") || !ft_strcmp(str, "rrb\n"))
		inst->ft_instruction(listb, lista);
	else if (!ft_strcmp(str, "ss\n") || !ft_strcmp(str, "rr\n") ||
			!ft_strcmp(str, "rrr\n"))
	{
		inst->ft_instruction(listb, lista);
		inst->ft_instruction(lista, listb);
	}
	else
	{
		ft_delinst(inst);
		ft_putstr("Error\n");
		return (NULL);
	}
	return (inst);
}



void					ft_exec_inst(t_pslist **lista,
		t_pslist **listb, char *str, t_opti **listopt)
{
	t_instructions	*inst;

	if (!(inst = ft_init_inst()))
		return ;
	if (!(ft_dispatcher_inst(inst, lista, listb, str)))
		return ;
	ft_delinst(inst);
	*listopt = ft_pushbackstr(str, *listopt);
}
