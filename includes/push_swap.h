/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayguillo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:08:19 by ayguillo          #+#    #+#             */
/*   Updated: 2019/01/25 18:46:55 by ayguillo         ###   ########.fr       */
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
void			ft_onearg(char *str, t_pslist **lista, t_pslist **lisbt);

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

/*
 ** Push_swap
*/

typedef struct	s_instructions
{
	char					*str;
	void					(*ft_instruction)(t_pslist **, t_pslist **);
	struct s_instructions	*next;
}				t_instructions;
void			ft_exec_inst(t_pslist **lista, t_pslist **listb, char *str);
int				ft_pslstlen(t_pslist *list);
int				ft_med(t_pslist *list, int len);
int				ft_min(t_pslist *list, int *i);
int				ft_max(t_pslist *list, int *j);
void			ft_shortsort(t_pslist **lista, t_pslist **listb);
void			ft_insertsort(t_pslist **lista, t_pslist **listb);
void			ft_quicksort(t_pslist **lista, t_pslist **listb, int len);

#endif
