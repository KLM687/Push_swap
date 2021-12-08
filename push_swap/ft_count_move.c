/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 10:52:22 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:18:29 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_movea(t_list **stackA, int grade)
{
	int	move;
	int	mina;
	int	maxa;

	mina = ft_searchmina(stackA);
	maxa = ft_searchmaxa(stackA);
	if (grade < mina)
		move = ft_spot(stackA, mina);
	else if (grade > maxa)
		move = ft_spotmax(stackA, maxa);
	else if (grade > mina && grade < maxa)
		move = ft_spotbtw(stackA, grade);
	return (move);
}

int	ft_moveb(t_list **stackB, int i)
{
	int	size;

	size = ft_lstsize(*stackB);
	if (i > (size / 2))
		i = size - i;
	return (i);
}

int	ft_count_move(t_list **stackA, t_list **stackB, int grade, int i)
{
	int	movea;
	int	moveb;
	int	totalmove;

	movea = ft_movea(stackA, grade);
	moveb = ft_moveb(stackB, i);
	totalmove = movea + moveb;
	return (totalmove);
}
