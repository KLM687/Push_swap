/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:32:48 by flee              #+#    #+#             */
/*   Updated: 2021/10/14 12:32:49 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sort(t_list **stack)
{
	t_list	*tmp;
	int		b;
	int		i;
	int		size;

	size = ft_lstsize(*stack);
	tmp = *stack;
	i = 0;
	b = tmp->content;
	while (tmp)
	{
		if (b <= tmp->content)
		{
			b = tmp->content;
			i++;
		}
		tmp = tmp->next;
	}
	if (i == size)
		return (1);
	else
		return (0);
}
