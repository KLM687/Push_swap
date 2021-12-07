/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:24:47 by flee              #+#    #+#             */
/*   Updated: 2021/11/29 14:45:44 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
	t_list *stackA;
	t_list *stackB;

	stackA = NULL;
	stackB = NULL;
	stackA = ft_argc_check(argc, argv, stackA);
	if	(stackA == NULL)
		return (EXIT_FAILURE);
	ft_sort(&stackA, &stackB);
	//ft_lstview(stackA);
	ft_lstclear(&stackA);
	return (EXIT_SUCCESS);
}
