/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushREST.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:49:06 by flee              #+#    #+#             */
/*   Updated: 2021/12/06 16:49:07 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_brain_moveup(int rrr, int rr, int move, t_list **stackA, t_list **stackB)
{
	if (rr <= rrr)
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

void	ft_brain_movedown(int rrr, int rr, int move, t_list **stackA, t_list **stackB)
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

int		ft_find_rrr(int rr, t_list **stackB)
{
	int	size;
	int rrr;

	size = ft_lstsize(*stackB);
	rrr = 0;
	if (size > 1)
		rrr = size - rr;
	return (rrr);
}

int     ft_searchmin(t_list **stackB)
{
    t_list  *tmp;
    int     min;

    tmp = *stackB;
    min = 9999;
    while (tmp)
    {
        if ((tmp->grade) < min)
            min = tmp->grade;
        tmp = tmp->next;
    }
    return (min);
}

int		ft_find_rr(int grade, t_list **stackB)
{
	t_list 	*tmp;
	int		min;
    int     rr;

    tmp = *stackB;
    min = ft_searchmin(stackB);
	rr = 0;
    while ((tmp->grade) != min)
    {
        tmp = tmp->next;
        rr++;
    }
    while (grade > (tmp->grade) && min > 0)
    {
        tmp = tmp->next; 
        rr++;
        if (tmp == NULL)
        {
            tmp = *stackB;
            rr = 0;
        }
        if (tmp->grade == min)
            min = 0;
    }
	return (rr);
}

int		ft_find_grade(int move, t_list **stackA, char pos)
{
	t_list *tmp;
	int grade;
	int size;
	int	i;

	size = ft_lstsize(*stackA);
	tmp = *stackA;
	i = 0;
	if (pos == 'd')
		move = size - move;
	while (i <= move)
	{
		grade = tmp->grade;
		tmp = tmp->next;
		i++;
	}
	return (grade);
}

void	ft_brainup(int move, t_list **stackA, t_list **stackB)
{
	int grade;
	int rrr;
	int rr;

	grade = ft_find_grade(move, stackA, 'u');
	rr = ft_find_rr(grade, stackB);
	rrr = ft_find_rrr(rr, stackB);
	//printf("rr = %d rrr = %d\n", rr ,rrr);
	ft_brain_moveup(rrr, rr, move, stackA, stackB);
	if (rrr < rr)
	{                                          
		while (rrr > 0)
		{
			ft_rev_rotate(stackB, 'b');
			rrr--;
		}	
	}
}	

void	ft_braindown(int move, t_list **stackA, t_list **stackB)
{
		int grade;
		int rrr;
		int rr;

		grade = ft_find_grade(move, stackA, 'd');
	    rr = ft_find_rr(grade, stackB);
	    rrr = ft_find_rrr(rr, stackB);
		//printf("rr = %d rrr = %d\n", rr ,rrr);
		ft_brain_movedown(rrr, rr, move, stackA, stackB);
		if (rr < rrr)
		{
			while (rr > 0)
			{
				ft_rotate(stackB, 'b');
				rr--;
			}
		}
}

int		ft_movedown(t_list **stackA)
{
	t_list 	*tmp;
	int		move;
	int		i;
	int 	size;

	tmp = *stackA;
	move = 0;
	i = 1;
	size = ft_lstsize(*stackA);
	while (tmp)
	{
		if (tmp->state == 0)
			move = i;
		tmp = tmp->next;
		i++;
	}
	move = size - move + 1;
	return (move);
}

int		ft_moveup(t_list **stackA)
{
	t_list *tmp;
	int	move;

	tmp = *stackA;
	move = 0;
	while (tmp && (tmp->state) != 0)
	{
		tmp = tmp->next;
		move++;	
	}
	return (move);
}

void    ft_push0(t_list **stackA, t_list **stackB)
{
	int move1;
	int move2;
	
	move1 = ft_moveup(stackA);
	move2 = ft_movedown(stackA);
	//printf("mv1 = %d mv2 = %d\n", move1 ,move2);
	if (move1 <= move2)
		ft_brainup(move1, stackA, stackB);
	else if (move2 < move1)
		ft_braindown(move2, stackA, stackB);
	ft_push(stackA, stackB, 'a');
}

int     ft_count0(t_list **stackA)
{
    t_list  *tmp;
    int     count;

    tmp = *stackA;
    count = 0;
    while (tmp)
    {
        if(tmp->state == 0 || tmp->state == 2)
            count++;
        tmp = tmp->next;
    }
    return (count);
}

void    ft_pushREST(t_list **stackA, t_list **stackB)
{
    int count;

    count = ft_count0(stackA);
    while (count > 0)
    {
        ft_push0(stackA, stackB);
        count--;
    }
	//ft_lstview(*stackA);
	//ft_lstview(*stackB);
}
