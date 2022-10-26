/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:55:09 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:47:08 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3_sort(t_list **stackA, int i)
{
	int	sort;

	if (i == 1)
		ft_rotate(stackA, 'a');
	else if (i == 2)
		ft_rev_rotate(stackA, 'a');
	else if (i == 3)
		ft_swap(stackA, 'a');
	sort = ft_check_sort(stackA);
	if (sort == 0)
		ft_swap(stackA, 'a');
}
