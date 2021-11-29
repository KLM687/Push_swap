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

void	ft_brain_movetop(int rrr, int rr, int move, t_list **stackA, t_list **stackB)
{
	if (rrr < rr)
	{
		while (rrr > 0 && move > 0)
		{
			ft_rev_rev(stackA, stackB);
			rrr--;
			move--;
		}
		while (rrr > 0)
		{
			ft_rev_rotate(stackB, 'b');
			rrr--;
		}
	}
	while (move > 0)
	{
		ft_rev_rotate(stackA, 'a');
		move--;
	}
}

void	ft_brain_movelow(int rrr, int rr, int move, t_list **stackA, t_list **stackB)
{
	if (rr < rrr)
	{
		while (rr > 0 && move > 0)
		{
			ft_rot_rot(stackA, stackB);
			rr--;
			move--;
		}
		while (rr > 0)
		{
			ft_rotate(stackB, 'b');
			rr--;
		}
	}
	while (move > 0)
	{
		ft_rotate(stackA, 'a');
		move--;
	}
}

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

int		ft_find_grade(int move, t_list **stackA, char *pos)
{
	t_list *tmp;
	int grade;
	int size;
	int	i;

	size = ft_lstsize(stackA);
	tmp = *stackA;
	i = 0;
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

void	ft_braintop(int move, t_list **stackA, t_list **stackB)
{
	int grade;
	int rrr;
	int rr;
	int i;

	grade = ft_find_grade(move, stackA, "top");
	rrr = ft_find_rrr(grade, stackB);
	rr = ft_find_rr(rrr, stackB);
	ft_brain_movetop(rrr, rr, move, stackA, stackB);
	if (rr < rrr)
	{                                          
		while (rr > 0)
		{
			ft_rotate(stackB, 'b');
			rr--;
		}
	}
}

void	ft_brainlow(int move, t_list **stackA, t_list **stackB)
{
		int grade;
		int rrr;
		int rr;
		int i;

		grade = ft_find_grade(move, stackA, "low");
		rrr = ft_find_rrr(grade, stackB);
		rr = ft_find_rr(rrr, stackB);
		ft_brain_movelow(rrr, rr, move, stackA, stackB);
		if (rrr < rr)
		{
			while (rrr > 0)
			{
				ft_rev_rotate(stackB, 'b');
				rrr--;
			}
		}
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
	while (tmp->grade >= chunk)
	{
		tmp = tmp->next;
		move++;	
	}
	return (move);
}


void	ft_sort100_sort(t_list **stackA,t_list **stackB, int chunk)
{
	int move1;
	int move2;
	
	move1 = ft_movetop(stackA, chunk);
	move2 = ft_movelow(stackA, chunk);
	if (move1 <= move2)
		ft_braintop(move1, stackA, stackB);
	else if (move2 < move1)
		ft_brainlow(move2, stackA, stackB);
}

void	ft_sort100(t_list **stackA, t_list **stackB)
{
	t_list *tmp;
	int	size;
	int chunk;
	int i;

	size = ft_lstsize(stackA);
	chunk = size / 5;
	i = 0;
	ft_grade(stackA);
	while (i < size)
	{
		while(i < chunk && i < size)
		{
			ft_sort100_sort(stackA, stackB, chunk);
			ft_push(stackA, stackB, 'a');
			i++;
		}
		chunk += chunk;
	}
	if (stackA != NULL)
		ft_push(stackA, stackB, 'a');
	tmp = *stackB;
	while (tmp)
	{
		ft_push(stackB, stackA, 'a');
		tmp = tmp->next;
	}
}

