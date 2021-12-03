/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:49:40 by flee              #+#    #+#             */
/*   Updated: 2021/11/29 15:43:26 by cesco            ###   ########.fr       */
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
	int grade;
	int	state;
	struct s_list *next;
}	t_list;

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
t_list	*ft_fill_argc(int argc, char **argv, t_list *stackA);
t_list	*ft_argc_check(int argc, char **argv, t_list *stackA);
int	ft_check_digit(int argc, char **argv);
int 	ft_check_duplicate(int argc, char **argv);
int	ft_check_duplicate2(int *str, int count);

void	ft_swap(t_list **stack, char a);
void	ft_swap_swap(t_list **stackA, t_list **stackB);
void	ft_push(t_list **source, t_list **target, char a);
void	ft_rotate(t_list **stack, char a);
void	ft_rot_rot(t_list **stackA, t_list **stackB);
void	ft_rev_rotate(t_list **stack, char a);
void	ft_rev_rev(t_list **stackA, t_list **stackB);

int	ft_check_sort(t_list **stack);

void	ft_sort(t_list **stackA, t_list **stackB);

void	ft_sort3(t_list **stackA);
void	ft_sort3_sort(t_list **stackA, int i);
void	ft_sort5(t_list **stackA, t_list **stackB);
void	ft_sort5_sort(t_list **stackA, t_list **stackB);
void	ft_sort100(t_list **stackA, t_list **stackB);
void 	ft_checkLIS(t_list **stackA);
void	ft_grade(t_list **stack);



void	ft_lstview(t_list *stack);

#endif
