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

t_list	**ft_fill_argc(char **argv, t_list **stack1);
t_list	**ft_argc_check(int argc, char **argv, t_list **stack1);

int main (int argc, char **argv)
{
	t_list **stack1;

	stack1 = NULL;
	stack1 = ft_argc_check(argc, argv, stack1);
	if (stack1 == NULL)
	{
		write(1, "error\n", 6);
		return (EXIT_FAILURE);
	}
}

t_list     **ft_argc_check(int argc, char **argv, t_list **stack1)
{
        if (argc == 1)
                return (NULL);
	else if (argc == 3)
                return (NULL);
	else if (argc >= 4)
                stack1 = ft_fill_argc(argv, stack1);
	return (stack1);
}

t_list	**ft_fill_argc(char **argv, t_list **stack1)
{
	int i;

	i = 0;
	while (argv[i][0] != '\0')
	{
		printf("%c\n",argv[i][0]);
		i++;
	}
	stack1 = NULL;
	return (stack1);
}

