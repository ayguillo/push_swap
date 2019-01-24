/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 10:54:55 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/24 14:44:09 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_instructions	*ft_addinst(char *str,
		void (*ft_ptr_instr)(t_pslist **, t_pslist **), t_instructions *list)
{
	t_instructions	*nvel;
	t_instructions	*tmp;

	if (!(nvel = malloc(sizeof(t_instructions))))
		return (NULL);
	if (!(nvel->str = ft_strdup(str)))
	{
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

	inst = ft_addinst("sa", ft_s, NULL);
	inst = ft_addinst("sb", ft_s, inst);
	inst = ft_addinst("ss", ft_s, inst);
	inst = ft_addinst("pa", ft_p, inst);
	inst = ft_addinst("pb", ft_p, inst);
	inst = ft_addinst("ra", ft_r, inst);
	inst = ft_addinst("rb", ft_r, inst);
	inst = ft_addinst("rr", ft_r, inst);
	inst = ft_addinst("rra", ft_rr, inst);
	inst = ft_addinst("rrb", ft_rr, inst);
	inst = ft_addinst("rrr", ft_rr, inst);
	return (inst);
}

static t_instructions	*ft_dispatcher_inst(t_instructions *inst,
		t_pslist **lista, t_pslist **listb, char *str)
{
	while (ft_strcmp(inst->str, str))
		inst = inst->next;
	if (!ft_strcmp(str, "sa") || !ft_strcmp(str, "pb") ||
		!ft_strcmp(str, "ra") || !ft_strcmp(str, "rra"))
		inst->ft_instruction(lista, listb);
	else if (!ft_strcmp(str, "sb") || !ft_strcmp(str, "pa") ||
		!ft_strcmp(str, "rb") || !ft_strcmp(str, "rrb"))
		inst->ft_instruction(listb, lista);
	else if (!ft_strcmp(str, "ss") || !ft_strcmp(str, "rb") ||
			!ft_strcmp(str, "rrb"))
	{
		inst->ft_instruction(listb, lista);
		inst->ft_instruction(lista, listb);
	}
	else
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	ft_putendl(str);
	return (inst);
}

void					ft_exec_inst(t_pslist **lista,
		t_pslist **listb, char *str)
{
	t_instructions	*inst;

	inst = ft_init_inst();
	if (!(ft_dispatcher_inst(inst, lista, listb, str)))
		return ;
}
