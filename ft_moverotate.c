/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moverotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:56:30 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:30:43 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_searchmaxa(t_list **stackA)
{
	t_list	*tmp;
	int		max;
	int		nb;

	tmp = *stackA;
	max = tmp->grade;
	while (tmp)
	{
		nb = tmp->grade;
		if (nb > max)
			max = nb;
		tmp = tmp->next;
	}
	return (max);
}

int	ft_searchmina(t_list **stackA)
{
	t_list	*tmp;
	int		min;
	int		nb;

	tmp = *stackA;
	min = tmp->grade;
	while (tmp)
	{
		nb = tmp->grade;
		if (nb < min)
			min = nb;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_moveb_grade(t_list **stackB, int grade)
{
	t_list	*tmp;
	int		move;
	int		size;

	tmp = *stackB;
	move = 0;
	size = ft_lstsize(*stackB);
	while (tmp->grade != grade)
	{
		tmp = tmp->next;
		move++;
	}
	if (move > (size / 2))
	{
		move = size - move;
		move *= -1;
	}
	return (move);
}

void	ft_moverotate(t_list **stackA, t_list **stackB, int movea, int moveb)
{	
	while (movea > 0 && moveb > 0)
	{
		ft_rot_rot(stackA, stackB, 'p');
		movea--;
		moveb--;
	}
	while (movea > 0)
	{
		ft_rotate(stackA, 'a');
		movea--;
	}
	while (moveb > 0)
	{
		ft_rotate(stackB, 'b');
		moveb--;
	}
}
