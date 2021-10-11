/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:49:40 by flee              #+#    #+#             */
/*   Updated: 2021/10/11 13:05:41 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct s_list
{
	int content;
	struct s_list *next;
}	t_list;

typedef struct s_control
{
	t_list *first;
	t_list *last;
}	t_control;

char    **ft_split(char const *str, char sep);
void    ft_lstadd_back(t_list **alst, t_list *new);
void    ft_lstadd_front(t_list **alst, t_list *new);
void    ft_lstclear(t_list **lst, void (*del)(void*));
void    ft_lstdelone(t_list *lst, void (*del)(void*));
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(int content);
int     ft_lstsize(t_list *lst);

#endif
