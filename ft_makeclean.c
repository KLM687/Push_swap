/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makeclean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 10:58:32 by cesco             #+#    #+#             */
/*   Updated: 2021/12/08 12:27:29 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findmin(t_list **stackA)
{
	t_list	*tmp;
	int		move;

	tmp = *stackA;
	move = 0;
	while (tmp && tmp->grade != 1)
	{
		move++;
		tmp = tmp->next;
	}
	return (move);
}

void	ft_makeclean(t_list **stackA)
{
	int	move;
	int	size;

	move = ft_findmin(stackA);
	size = ft_lstsize(*stackA);
	if (move > (size / 2))
	{
		move = size - move;
		move *= -1;
	}
	while (move > 0)
	{
		ft_rotate(stackA, 'a');
		move--;
	}
	while (move < 0)
	{
		ft_rev_rotate(stackA, 'a');
		move++;
	}
}
