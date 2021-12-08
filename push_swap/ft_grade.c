/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grade.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:04:15 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:24:17 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ok(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->grade == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_grade(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp_min;
	int		grade;
	int		min;

	grade = 1;
	while (ft_ok(stack))
	{
		tmp = *stack;
		while (tmp && tmp->grade != 0)
			tmp = tmp->next;
		min = tmp->content;
		tmp_min = tmp;
		while (tmp)
		{
			if (tmp->content < min && tmp->grade == 0)
			{
				min = tmp->content;
				tmp_min = tmp;
			}
			tmp = tmp->next;
		}
		tmp_min->grade = grade;
		grade++;
	}
}
