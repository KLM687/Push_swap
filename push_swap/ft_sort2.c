/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:24:57 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:46:30 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort2(t_list **stackA)
{
	t_list	*tmp;

	tmp = *stackA;
	ft_grade(stackA);
	if (tmp->grade > tmp->next->grade)
		ft_swap(stackA, 'a');
}
