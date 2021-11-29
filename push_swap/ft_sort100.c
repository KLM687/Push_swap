/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:13 by cesco             #+#    #+#             */
/*   Updated: 2021/11/29 16:15:21 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_rr(int rrr, t_list **stackB)
{
	int	size;
	int rr;

	size = ft_lstsize(stackB);
	rr = size - rrr;
	return (rr);
}

int		ft_find_rrr(int grade, t_list **stackB)
{
	t_list 	*tmp;
	int		rrr;	

	tmp = *stackB;
	rrr = 0;
	if (tmp != NULL)
	{
		while (tmp->grade < grade)
		{
			tmp = tmp->next;
			rrr++;
		}
	}
	return (rrr);
}

int		ft_find_gradetop(int move, t_list **stackA, char *pos)
{
	t_list *tmp;
	int grade;
	int size;
	int	i;

	size = ft_lstsize(stackA);
	tmp = *stackA;
	i = 0;
	grade = tmp->grade;
	if (pos == "low")
		move = move - size + 1;
	while (i <= move)
	{
		grade = tmp->grade;
		tmp = tmp->next;
		i++;
	}
	return (grade);
}

int		ft_braintop(int move, t_list **stackA, t_list **stackB)
{
		int grade;
		int rrr;
		int rr;
		int i;

		grade = ft_find_grade(move, stackA, "top");
		rrr = ft_find_rrr(grade, stackB);
		rr = ft_find_rr(rrr, stackB);
		ft_brain_move (rrr, rr, move, stackA, stackB);
}

int		ft_movelow(t_list **stackA, int chunk)
{
	t_list 	*tmp;
	int		move;
	int		i;
	int 	size;

	tmp = stackA;
	move = 0;
	i = 1;
	size = ft_lstsize(stackA);
	while (tmp)
	{
		if (tmp->grade <= chunk)
			move = i;
		tmp = tmp->next;
		i++;
	}
	move = size - move + 1;
	return (move);
}

int		ft_movetop(t_list **stackA, int chunk)
{
	t_list *tmp;
	int	move;

	move = 0;
	tmp = *stackA;
	while (tmp->grade > chunk)
	{
		tmp = tmp->next;
		move++;	
	}
	return (move);
}


int		ft_sort100_sort(t_list **stackA,t_list **stackB, int chunk)
{
	int move1;
	int move2;
	int i;

	i = 0;
	move1 = ft_movetop(stackA, chunk);
	move2 = ft_movelow(stackA, chunk);
	if (move1 <= move2)
		i = ft_braintop(move1, stackA, stackB);
	else
}

void	ft_sort100(t_list **stackA, t_list **stackB)
{
	int	size;
	int chunk;
	int i;

	size = ft_lstsize(stackA);
	chunk = size / 5;
	i = 0;
	ft_grade(stackA);
	while (i < chunk)
		i = ft_sort100_sort(stackA, stackB, chunk);
}

