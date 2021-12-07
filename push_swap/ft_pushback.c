/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushREST.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:16:11 by flee              #+#    #+#             */
/*   Updated: 2021/12/06 14:16:13 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int		ft_spotbtw(t_list **stackA, int grade) // compte les moves pour placer le nb dans la bonne zone
{
	t_list 	*tmpA;
	t_list	*tmpB;
	int 	move;
	int 	size;

	tmpA = ft_lstlast(*stackA);
	tmpB = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while (grade < (tmpA->grade) || grade > (tmpB->grade))
	{
		tmpA = tmpB;
		tmpB = tmpB->next;
		move++;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}

int		ft_spotbtwpush(t_list **stackA, int grade) // compte les moves pour placer le nb dans la bonne zone retourne posi ou nega
{
	t_list 	*tmpA;
	t_list	*tmpB;
	int 	move;
	int 	size;

	tmpA = ft_lstlast(*stackA);
	tmpB = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while (grade < (tmpA->grade) || grade > (tmpB->grade))
	{
		tmpA = tmpB;
		tmpB = tmpB->next;
		move++;
	}
	if (move > (size / 2))
	{
		move = size - move;
		move *= -1;
	}
	return (move);
}

int		ft_spot(t_list **stackA, int nb) //compte les moves pour deplacer min
{
	t_list 	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while(tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}

int		ft_spotmax(t_list **stackA, int nb) //compte les moves pour deplacer max
{
	t_list 	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 1;
	size = ft_lstsize(*stackA);
	while(tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
		move = size - move;
	return (move);
}

int		ft_spotmaxpush(t_list **stackA, int nb) //compte les moves pour deplacer max
{
	t_list 	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 1;
	size = ft_lstsize(*stackA);
	while(tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
	{
		move = size - move;
		move *= -1;
	}
	return (move);
}

int		ft_spotpush(t_list **stackA, int nb) //compte les moves pour deplacer min pou max et retourne nega ou posi
{
	t_list 	*tmp;
	int		move;
	int		size;

	tmp = *stackA;
	move = 0;
	size = ft_lstsize(*stackA);
	while(tmp->grade != nb)
	{
		move++;
		tmp = tmp->next;
	}
	if (move > (size / 2))
	{
		move = size - move;
		move *= -1;
	}
	return (move);
}

int		ft_searchmaxA(t_list **stackA) // trouve le nb max
{
	t_list 	*tmp;
	int 	max;
	int 	nb;

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

int		ft_searchminA(t_list **stackA) // trouve le nb min
{
	t_list 	*tmp;
	int 	min;
	int 	nb;

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

int		ft_moveA(t_list **stackA, int grade) // compte move de A
{
	int move;
	int minA;
	int	maxA;

	minA = ft_searchminA(stackA);
	maxA = ft_searchmaxA(stackA);
	if (grade < minA)
		move = ft_spot(stackA, minA);
	else if (grade > maxA)
		move = ft_spotmax(stackA, maxA);
	else if (grade > minA && grade < maxA)
		move = ft_spotbtw(stackA, grade);
	return (move);
}

int		ft_moveB(t_list **stackB, int i) // compte move de B
{
	int size;

	size = ft_lstsize(*stackB);
	if (i > (size / 2))
		i = size - i;
	return (i);
}

int		ft_count_move(t_list **stackA, t_list **stackB, int grade, int i) // compte move de A et B
{
	int	moveA;
	int	moveB;
	int totalmove;

	moveA = ft_moveA(stackA, grade);
	moveB = ft_moveB(stackB, i);
	totalmove = moveA + moveB;
	return (totalmove);
}

int		ft_moveB_grade(t_list **stackB, int grade) // compte les moves de B trouve rr ou rrr
{
	t_list 	*tmp;
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

void	ft_moverotate(t_list **stackA, t_list **stackB, int moveA, int moveB) // rot rot le nb de fois ou rot
{	
	while (moveA > 0 && moveB > 0)
	{
		ft_rot_rot(stackA, stackB);
		moveA--;
		moveB--;
	}
	while (moveA > 0)
	{
		ft_rotate(stackA, 'a');
		moveA--;
	}
	while (moveB > 0)
	{
		ft_rotate(stackB, 'b');
		moveB--;
	}
}

void	ft_moverev(t_list **stackA, t_list **stackB, int moveA, int moveB) // rev rev le nb de fois ou rev
{	
	while (moveA < 0 && moveB < 0)
	{
		ft_rev_rev(stackA, stackB);
		moveA++;
		moveB++;
	}
	while (moveA < 0)
	{
		ft_rev_rotate(stackA, 'a');
		moveA++;
	}
	while (moveB < 0)
	{
		ft_rev_rotate(stackB, 'b');
		moveB++;
	}
}

int		ft_moveApush(t_list **stackA, int grade) // compte move de A et negatif aussi
{
	int move;
	int minA;
	int	maxA;

	minA = ft_searchminA(stackA);
	maxA = ft_searchmaxA(stackA);
	if (grade < minA)
		move = ft_spotpush(stackA, minA);
	else if (grade > maxA)
		move = ft_spotmaxpush(stackA, maxA);
	else if (grade > minA && grade < maxA)
		move = ft_spotbtwpush(stackA, grade);
	return (move);
}

void	ft_finalpush(t_list **stackA, t_list **stackB, int grade)
{
	int moveA;
	int	moveB;
	
	moveA = ft_moveApush(stackA, grade);
	//printf("moveA = %d\n",moveA);
	moveB = ft_moveB_grade(stackB, grade);
	//printf("moveb = %d\n",moveB);
	if (moveA >= 0 || moveB >= 0)
		ft_moverotate(stackA, stackB, moveA, moveB);
	if(moveA <= 0 || moveB <= 0)
		ft_moverev(stackA, stackB, moveA, moveB);
	//printf("WTF\n");
	ft_push(stackB, stackA, 'b');
}

void	ft_push_back1(t_list **stackA, t_list **stackB) //compare les moves de A et B
{
	t_list 	*tmp;
	int		grade;
	int		move;
	int		minmove;
	int 	i;

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
	//printf("minmove = %d grade = %d\n",minmove , grade);
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