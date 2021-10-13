/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:36:13 by flee              #+#    #+#             */
/*   Updated: 2021/10/13 14:36:14 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **source, t_list **target)
{
	t_list *tmp;
	if (*source != NULL)
	{
		tmp = (*source)->next;
		ft_lstadd_front(target, *source);
		*source = tmp;
	}
}