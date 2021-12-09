/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 10:32:52 by flee              #+#    #+#             */
/*   Updated: 2021/10/11 13:05:25 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list) * 1);
	if (tmp == NULL)
		return (0);
	if (tmp)
	{
		tmp->content = content;
		tmp->grade = 0;
		tmp->state = 0;
		tmp->next = NULL;
	}
	return (tmp);
}
