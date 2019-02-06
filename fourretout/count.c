/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 16:04:14 by ayguillo          #+#    #+#             */
/*   Updated: 2019/02/06 16:04:26 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count(t_pslist *lista, t_pslist *listb, int *waya, int *wayb)
{
	int 		tab[6];
	t_pslist	*tmp;
	int			lena;
	int			lenb;

	tab[0] = 0;
	tab[2] = 0;
	tab[1] = 2147483647;
	tab[4] = 0;
	*waya = 1;
	*wayb = 1;
	tmp = lista;
	lena = ft_pslstlen(lista);
	lenb = ft_pslstlen(listb);
	if (lenb == 1)
		return(listb->content);
	while (listb->next)
	{
		tab[3] = 0;
		tab[5] = 1;
		tmp = lista;
		while (tab[5] < lena && tmp->next)
		{
			if (tmp->content < listb->content
					&& tmp->next->content > listb->content)
				break;
			tmp = tmp->next;
			tab[3]++;
			tab[5]++;
			tab[0]++;
			if (tab[3] > lena / 2)
			{
				tab[0] = tab[0] - lena / 2;
				*waya = -1;
			}
			if (tab[5] == lena)
			{
				tab[5] = 0;
				tab[0] = tab[0] - lena;
			}
		}
		listb = listb->next;
		tab[4]++;
		tab[0]++;
		if (tab[4] > lenb / 2)
		{
			tab[0] = tab[0] - lenb / 2;
			*wayb = -1;
		}
		if (tab[1] > tab[0])
		{
			tab[2] = listb->content;
			tab[1] = tab[0];
		}
		tab[0] = tab[0] - tab[3] + 1;
	}
	return (tab[2]);
}
