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

void	ft_rotate(t_list **stack)
{
	t_list	**tmp;
	t_list  *tmp1;
	t_list 	*tmp2;
	int 	size;
	int 	i;

	tmp = NULL;	
	tmp1 = *stack;
	size = ft_lstsize(tmp1);
	i = 0;
	ft_push(stack, tmp);
	while (i < (size - 1))
		tmp1 = tmp1->next;
	tmp2 = tmp1;
	tmp1=tmp1->next;
	tmp2->next = NULL;
	ft_lstadd_front(stack, tmp1);
	ft_lstadd_back(stack, *tmp);
}