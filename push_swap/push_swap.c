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