/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:11 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:39:40 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moverev(t_list **stackA, t_list **stackB, int movea, int moveb)
{	
	while (movea < 0 && moveb < 0)
	{
		ft_rev_rev(stackA, stackB);
		movea++;
		moveb++;
	}
	while (movea < 0)
	{
		ft_rev_rotate(stackA, 'a');
		movea++;
	}
	while (moveb < 0)
	{
		ft_rev_rotate(stackB, 'b');
		moveb++;
	}
}

int	ft_moveapush(t_list **stackA, int grade)
{
	int	move;
	int	mina;
	int	maxa;

	mina = ft_searchmina(stackA);
	maxa = ft_searchmaxa(stackA);
	if (grade < mina)
		move = ft_spotpush(stackA, mina);
	else if (grade > maxa)
		move = ft_spotmaxpush(stackA, maxa);
	else if (grade > mina && grade < maxa)
		move = ft_spotbtwpush(stackA, grade);
	return (move);
}

void	ft_finalpush(t_list **stackA, t_list **stackB, int grade)
{
	int	movea;
	int	moveb;

	movea = ft_moveapush(stackA, grade);
	moveb = ft_moveb_grade(stackB, grade);
	if (movea >= 0 || moveb >= 0)
		ft_moverotate(stackA, stackB, movea, moveb);
	if (movea <= 0 || moveb <= 0)
		ft_moverev(stackA, stackB, movea, moveb);
	ft_push(stackB, stackA, 'a');
}

void	ft_push_back1(t_list **stackA, t_list **stackB)
{
	t_list	*tmp;
	int		grade;
	int		move;
	int		minmove;
	int		i;

	i = 0;
	tmp = *stackB;
	minmove = 999;
	grade = 0;
	while (tmp)
	{
		move = ft_count_move(stackA, stackB, tmp->grade, i);
		if (move < minmove)
		{
			minmove = move;
			grade = tmp->grade;
		}
		tmp = tmp->next;
		i++;
	}
	ft_finalpush(stackA, stackB, grade);
}

void	ft_pushback(t_list **stackA, t_list **stackB)
{
	int	size;

	size = ft_lstsize(*stackB);
	while (size > 0)
	{
		ft_push_back1(stackA, stackB);
		size--;
	}	
}
