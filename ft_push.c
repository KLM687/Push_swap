/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:13 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:31:41 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **source, t_list **target, char a)
{
	t_list	*tmp;

	if (*source != NULL)
	{
		tmp = (*source)->next;
		ft_lstadd_front(target, *source);
		*source = tmp;
	}
	if (a == 'n')
		write(1, "", 0);
	else if (a == 'a')
		write(1, "pa\n", 3);
	else
		write(1, "pb\n", 3);
}
