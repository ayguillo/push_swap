/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:08:19 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/22 20:05:38 by ayguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <stdio.h>

/* 
 ** List manipulation
*/

typedef struct	s_pslist
{
	int				content;
	struct s_pslist	*next;
}				t_pslist;

t_pslist		*ft_addl(t_pslist *list, int nw);
t_pslist		*ft_addr(t_pslist *list, int nw);
t_pslist		*ft_delhead(t_pslist *list);
void			ft_delallst(t_pslist **list);
void			ft_printlist_nb(t_pslist *list);
void			ft_freelist(t_pslist **lista, t_pslist **listb);

/*
 ** Instructions
*/

void			ft_s(t_pslist **lista, t_pslist **listb);
void			ft_p(t_pslist **lista, t_pslist **listb);
void			ft_r(t_pslist **lista, t_pslist **listb);
void			ft_rr(t_pslist **lista, t_pslist **listb);

/*
 ** Shared
*/

int				ft_verif(t_pslist *list);
int				ft_parsing(char *str, t_pslist **lista, t_pslist **listb);

/*
 ** Checker
*/

typedef struct	s_check
{
	char			*str;
	void			(*ft_instruction1)(t_pslist **, t_pslist **);
	struct s_check	*next;

}				t_check;
void			ft_checker(char *line, t_pslist **lista, t_pslist **listb,
		int *err);
void			ft_delchecklist(t_check **list);

#endif
