/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:47:37 by flee              #+#    #+#             */
/*   Updated: 2021/10/14 11:47:41 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_list **stackA)
{
	t_list *tmp;
	int	max;
	int	sort;
	int 	i;

	tmp = *stackA;
	sort = ft_check_sort(stackA);
	i = 0;
	max = tmp->content;
	if (sort == 0)
	{
		while (tmp)
		{
			if (max <= tmp->content)
			{	
				max = tmp->content;
				i++;
			}
			tmp = tmp->next;
		}
		ft_sort3_sort(stackA, i);
	}
}
