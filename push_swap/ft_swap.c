/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 12:19:09 by flee              #+#    #+#             */
/*   Updated: 2021/10/13 12:19:11 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **stack, char a)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3; 
	int 	size;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		tmp = *stack;
		tmp2 = (*stack)->next;
		tmp3 = (*stack)->next->next;
		tmp2->next = tmp;
		tmp->next = tmp3;
		*stack = tmp2;
	}
	if (a == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}
