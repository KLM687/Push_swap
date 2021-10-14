/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 10:22:21 by flee              #+#    #+#             */
/*   Updated: 2021/10/14 10:22:23 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rev_rotate(t_list **stack, char a)
{
	t_list 	*tmp;
	t_list 	*tmp2;
	int 	size;
	
	size = ft_lstsize(*stack);
	if (size > 1)
	{
		tmp = NULL;
		tmp2 =ft_lstlast(*stack);
		size = ft_lstsize(*stack);
		ft_push(&tmp2, &tmp);
		ft_lstadd_front(stack, tmp);
		tmp = *stack;
		while (size > 1)
		{
			tmp = tmp->next;
			size--;
		}
		tmp->next = NULL;
	}
	if (a == 'a')
		write(0, "rra\n", 4);
	else
		write(0, "rrb\n", 4);
}