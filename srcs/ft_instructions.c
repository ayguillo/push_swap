/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:38:57 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/22 18:53:11 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_s(t_pslist **lista, t_pslist **listb)
{
	int			tmp;

	*listb = *listb;
	if (!(*lista) || !lista || (*lista)->next == NULL)
		return ;
	tmp = (*lista)->content;
	(*lista)->content = (*lista)->next->content;
	(*lista)->next->content = tmp;
}

void	ft_p(t_pslist **lista, t_pslist **listb)
{
	int			save;

	if (!(*lista) || !lista)
	{
		return ;
	}
	save = (*lista)->content;
	*listb = ft_addl(*listb, save);
	*lista = ft_delhead(*lista);
}

void	ft_r(t_pslist **lista, t_pslist **listb)
{
	t_pslist	*save;
	t_pslist	*first;

	*listb = *listb;
	if (!lista || !(*lista) || (*lista)->next == NULL)
		return ;
	first = *lista;
	save = (*lista)->next;
	while ((*lista)->next)
		*lista = (*lista)->next;
	(*lista)->next = first;
	(*lista) = save;
	first->next = NULL;
}

void	ft_rr(t_pslist **lista, t_pslist **listb)
{
	t_pslist	*first;
	t_pslist	*save;

	*listb = *listb;
	if (!lista || !(*lista) || (*lista)->next == NULL)
		return ;
	first = (*lista);
	save = (*lista);
	while (save->next->next)
		save = save->next;
	while ((*lista)->next)
		(*lista) = (*lista)->next;
	(*lista)->next = first;
	save->next = NULL;
}
