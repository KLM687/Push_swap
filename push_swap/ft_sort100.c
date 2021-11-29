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

int		ft_movelow(t_list **stackA, int chunk, int size)
{
	t_list 	*tmp;
	int		move;
	int		i;

	tmp = stackA;
	move = 0;
	i = 1;
	while (tmp)
	{
		if (tmp->grade <= chunk)
			move = i;
		tmp = tmp->next;
		i++;
	}
	move = size - move + 1;

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


int		ft_sort100_sort(t_list **stackA,t_list **stackB, int chunk, int size)
{
	int move1;
	int move2;

	move1 = ft_movetop(stackA, chunk);
	move2 = ft_movelow(stackA, chunk, size);


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
		i = ft_sort100_sort(stackA, stackB, chunk, size);
}

