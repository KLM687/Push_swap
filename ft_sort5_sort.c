/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 12:48:35 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:49:54 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_top5move(t_list **stack, int target)
{
	t_list	*tmp;
	int		mid;
	int		pos;

	mid = (ft_lstsize(*stack) / 2);
	pos = 0;
	tmp = *stack;
	while (tmp->grade != target)
	{
		tmp = tmp->next;
		pos++;
	}
	if (pos <= mid)
		return (-1);
	return (1);
}

void	ft_move_min(t_list **stackA, t_list **stackB, int grade)
{
	int	i;

	i = ft_top5move(stackA, grade);
	while ((*stackA)->grade != grade)
	{
		if (i == -1)
			ft_rotate(stackA, 'a');
		else
			ft_rev_rotate(stackA, 'a');
	}
	ft_push(stackA, stackB, 'b');
}

void	ft_sort5_sort(t_list **stackA, t_list **stackB)
{
	ft_move_min(stackA, stackB, 1);
	ft_move_min(stackA, stackB, 2);
	ft_sort3(stackA);
	ft_push(stackB, stackA, 'a');
	ft_push(stackB, stackA, 'a');
}
