/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:25:31 by flee              #+#    #+#             */
/*   Updated: 2021/10/13 15:25:33 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **stack, char a)
{
	t_list	*tmp;
	int 	size;

	size = ft_lstsize(*stack);
	if (size > 1)
	{
		tmp = NULL;
		ft_push(stack, &tmp, 'n');
		tmp->next = NULL;
		ft_lstadd_back(stack, tmp);
	}
	if (a == 'a')
		write(1, "ra\n", 3);
	else if (a == 'b')
		write(1, "rb\n", 3);
}