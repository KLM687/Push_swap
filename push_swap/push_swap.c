/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:24:47 by flee              #+#    #+#             */
/*   Updated: 2021/10/11 12:46:18 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

t_list	*ft_fill_argc(int argc, char **argv, t_list *stack1);
t_list	*ft_argc_check(int argc, char **argv, t_list *stack1);
int		ft_check_stack1(int argc, char **argv);

int main (int argc, char **argv)
{
	t_list *stack1;
	int nb;

	stack1 = NULL;
	stack1 = ft_argc_check(argc, argv, stack1);
	if	(stack1 == NULL)
	{
		write(1, "error\n", 6);
		return (EXIT_FAILURE);
	}
	nb = ft_lstsize(stack1);
	return (EXIT_SUCCESS);
}

t_list	*ft_argc_check(int argc, char **argv, t_list *stack1)
{
    if (argc < 4)
        return (NULL);
	else
        stack1 = ft_fill_argc(argc, argv, stack1);
	return (stack1);
}

t_list	*ft_fill_argc(int argc, char **argv, t_list *stack1)
{
	int 	i;
	
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return(stack1);
}
