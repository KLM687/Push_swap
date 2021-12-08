/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:41:29 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:45:34 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stackA, t_list **stackB)
{
	int	size;
	int	sort;

	(*stackB) = NULL;
	size = ft_lstsize(*stackA);
	sort = ft_check_sort(stackA);
	if (size == 2 && sort == 0)
		ft_sort2(stackA);
	else if (size == 3 && sort == 0)
		ft_sort3(stackA);
	else if (size <= 5 && sort == 0)
		ft_sort5(stackA, stackB);
	else if (size > 5 && sort == 0)
		ft_sort100(stackA, stackB);
}
