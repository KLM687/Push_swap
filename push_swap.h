/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:49:40 by flee              #+#    #+#             */
/*   Updated: 2021/12/09 10:16:25 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				grade;
	int				state;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_atoi(char *str);
int		ft_isdigit(int character);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
t_list	*ft_fill_argc(int argc, char **argv, t_list *stackA);
t_list	*ft_argc_check(int argc, char **argv, t_list *stackA);
int		ft_check_int(int argc, char **argv, t_list *stackA);
int		ft_atoi_checkint(char *str);
int		ft_check_digit(int argc, char **argv);
int		ft_check_duplicate(int argc, char **argv);
int		ft_check_duplicate2(int *str, int count);

void	ft_swap(t_list **stack, char a);
void	ft_swap_swap(t_list **stackA, t_list **stackB, char a);
void	ft_push(t_list **source, t_list **target, char a);
void	ft_rotate(t_list **stack, char a);
void	ft_rot_rot(t_list **stackA, t_list **stackB, char a);
void	ft_rev_rotate(t_list **stack, char a);
void	ft_rev_rev(t_list **stackA, t_list **stackB, char a);

int		ft_check_sort(t_list **stack);

void	ft_sort(t_list **stackA, t_list **stackB);

void	ft_sort2(t_list **stackA);
void	ft_sort3(t_list **stackA);
void	ft_sort3_sort(t_list **stackA, int i);
void	ft_sort5(t_list **stackA, t_list **stackB);
void	ft_sort5_sort(t_list **stackA, t_list **stackB);
void	ft_sort100(t_list **stackA, t_list **stackB);

int		ft_spotpush(t_list **stackA, int nb);
int		ft_spotmaxpush(t_list **stackA, int nb);
int		ft_spotbtwpush(t_list **stackA, int grade);
int		ft_spot(t_list **stackA, int nb);
int		ft_spotmax(t_list **stackA, int nb);
int		ft_spotbtw(t_list **stackA, int grade);
int		ft_count_move(t_list **stackA, t_list **stackB, int grade, int i);
void	ft_moverotate(t_list **stackA, t_list **stackB, int movea, int moveb);
void	ft_moverev(t_list **stackA, t_list **stackB, int movea, int moveb);
int		ft_moveb_grade(t_list **stackB, int grade);
int		ft_searchmina(t_list **stackA);
int		ft_searchmaxa(t_list **stackA);

void	ft_checklis(t_list **stackA);
t_list	*ft_set_beacon2(t_list *tmp, t_list *beacon2);
t_list	*ft_change_beacon2(t_list *tmp, t_list *beacon2);
void	ft_resetlis(t_list **stackA, int size);
int		ft_countlis(t_list **stackA, int size);
void	ft_pushlds(t_list **stackA, t_list **stackB);
void	ft_pushback(t_list **stackA, t_list **stackB);
void	ft_makeclean(t_list **stackA);
void	ft_grade(t_list **stack);
void	ft_lstview(t_list *stack);

#endif
