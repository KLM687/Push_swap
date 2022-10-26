/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:46:44 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:53:52 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_spotbtw(t_list **stackA, int grade)
{
	t_list	*tmpa;
	t_list	*tmpb;
	int		move;
	int		size;

	tmpa = ft_lstlast(*stackA);
	tmpb = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while (grade < (tmpa->grade) || grade > (tmpb->grade))
	{
		tmpa = tmpb;
		tmpb = tmpb->next;
		move++;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}

int	ft_spot(t_list **stackA, int nb)
{
	t_list	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while (tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}

int	ft_spotmax(t_list **stackA, int nb)
{
	t_list	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 1;
	size = ft_lstsize(*stackA);
	while (tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}
