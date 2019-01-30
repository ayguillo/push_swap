/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 09:32:47 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/29 09:49:27 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*void	ft_visu(t_pslist *lista, t_pslist *listb)
{
	system("clear");
	ft_printf("_____PILE A_____|\n");
	if (lista)
		ft_printlist_nb(lista);
	ft_printf("_____PILE B_____|\n");
	if (listb)
		ft_printlist_nb(listb);
	usleep(10000);
}*/

void			ft_visu(t_pslist *lista, t_pslist *listb)
{
	system("clear");
	ft_printf("-------------------------\n");
	ft_printf("\n        PILE A \n\n");
	if (lista != NULL)
		ft_printlist_nb(lista);
	ft_printf("\n-------------------------\n");
	ft_printf("\n        PILE B \n\n");
	if (listb != NULL)
		ft_printlist_nb(listb);
	ft_printf("\n-------------------------\n");
	usleep(100000);
}
