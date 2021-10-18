/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:41:29 by flee              #+#    #+#             */
/*   Updated: 2021/10/14 11:41:30 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **stackA, t_list **stackB)
{
	int size;

	(*stackB) =NULL;	
	size = ft_lstsize(*stackA);
	if (size == 3)
		ft_sort3(stackA);
	/*else if(size <= 5)
		ft_sort5(stackA, stackB);*/
	//ft_lstview(*stackA);
}