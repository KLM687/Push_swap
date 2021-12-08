/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checklis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:24:39 by cesco             #+#    #+#             */
/*   Updated: 2021/12/08 12:08:23 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lispart2(t_list *tmp, t_list *beacon1, t_list *beacon2, int grade)
{
	int	state;

	tmp = tmp->next;
	state = tmp->state;
	grade = tmp->grade;
	while (state == 0)
	{
		if (beacon2 == NULL && grade > (beacon1->grade))
			beacon2 = ft_set_beacon2(tmp, beacon2);
		if (beacon2 != NULL)
		{
			if (grade < (beacon2->grade) && grade > (beacon1->grade))
				beacon2 = ft_change_beacon2(tmp, beacon2);
			else if (grade > (beacon2->grade) && beacon2)
			{
				beacon1 = beacon2;
				beacon2 = tmp;
				beacon2->state = 1;
			}
		}
		tmp = tmp->next;
		state = tmp->state;
		grade = tmp->grade;
	}
}

void	ft_lis(t_list **stackA, int i)
{
	t_list	*tmp;
	t_list	*beacon1;
	t_list	*beacon2;
	int		grade;

	tmp = *stackA;
	grade = tmp->grade;
	while (grade != i)
	{
		tmp = tmp->next;
		grade = tmp->grade;
	}
	tmp->state = 1;
	beacon1 = tmp;
	beacon2 = NULL;
	ft_lispart2(tmp, beacon1, beacon2, grade);
}

int	ft_toplis(t_list **stackA, int size)
{
	int	i;
	int	memory;
	int	lis;
	int	maxlis;

	maxlis = 0;
	i = 1;
	while (i < size + 1)
	{
		ft_lis(stackA, i);
		lis = ft_countlis(stackA, size);
		if (lis >= maxlis)
		{
			maxlis = lis;
			memory = i;
		}
		ft_resetlis(stackA, size);
		i++;
	}
	ft_lis(stackA, memory);
	return (maxlis);
}

void	ft_checklis(t_list **stackA)
{
	t_list	*tmp;
	int		size;
	int		i;

	tmp = *stackA;
	size = ft_lstsize(*stackA);
	i = 0;
	while (i < size - 1)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = *stackA;
	ft_toplis(stackA, size);
	tmp->next = NULL;
}
