/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:32:10 by flee              #+#    #+#             */
/*   Updated: 2021/12/09 14:11:20 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	int				content;
	int				grade;
	int				state;
	struct s_list	*next;
}	t_list;

int		ft_strlengnl(const char *str, int state);
size_t	ft_strlcpy(char *dest, const char *src, unsigned int size);
char	*ft_strjoin(char *s1, char const *s2, int read_return);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_substr(char *s, unsigned int start, size_t len, int state);
int		ft_check(char *memory);
char	*ft_fill_memory(char *memory, char *buf, int fd);
char	*get_next_line(int fd);

void	ft_do_rev_rotate(char *line, t_list **stacka, t_list **stackb);
void	ft_do_rotate(char *line, t_list **stacka, t_list **stackb);
void	ft_do_push(char *line, t_list **stacka, t_list **stackb);
void	ft_do_swap(char *line, t_list **stacka, t_list **stackb);

void	ft_lstadd_back(t_list **alst, t_list *newlst);
void	ft_lstadd_front(t_list **alst, t_list *newlst);
void	ft_lstclear(t_list **lst);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_atoi(char *str);
//char	*ft_itoa(int nb);
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
void	ft_lstview(t_list *stack);

#endif
