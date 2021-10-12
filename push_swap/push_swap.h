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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

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

void    ft_lstadd_back(t_list **alst, t_list *new);
void    ft_lstadd_front(t_list **alst, t_list *new);
void    ft_lstclear(t_list **lst);
void    ft_lstdelone(t_list *lst, void (*del)(void*));
t_list  *ft_lstlast(t_list *lst);
t_list  *ft_lstnew(int content);
int     ft_lstsize(t_list *lst);

int	ft_atoi(char *str);
char	*ft_itoa(int nb);
int 	ft_isdigit (int character);
char	*ft_strdup(char *src);
size_t	ft_strlen (const char *str);
t_list	*ft_fill_argc(int argc, char **argv, t_list *stack1);
t_list	*ft_argc_check(int argc, char **argv, t_list *stack1);
int	ft_check_digit(int argc, char **argv);
int 	ft_check_duplicate(int argc, char **argv);
int	ft_check_duplicate2(int *str, int count);

#endif