/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 15:37:26 by flee              #+#    #+#             */
/*   Updated: 2021/10/11 13:04:00 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;
	t_list	*memory;

	tmp = *lst;
	while (tmp)
	{
		memory = tmp->next;
		tmp->next = NULL;
		free(tmp);
		tmp = memory;
	}
	*lst = NULL;
}
