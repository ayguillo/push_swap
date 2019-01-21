/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 21:51:57 by tdelabro          #+#    #+#             */
/*   Updated: 2019/01/21 13:26:46 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putlst(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (head)
	{
		ft_putstr(head->content);
		head = head->next;
	}
}
