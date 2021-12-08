/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:51:24 by flee              #+#    #+#             */
/*   Updated: 2021/12/07 15:51:25 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkstackint(t_list *stackA)
{
	t_list	*tmp;

	tmp = stackA;
	while (tmp)
	{
		if (tmp->content == 0)
		{
			ft_lstclear(&stackA);
			return (1);
		}
		tmp = tmp->next;
	}
	ft_lstclear(&stackA);
	return (0);
}

int	ft_check_int(int argc, char **argv, t_list *stackA)
{
	int	i;
	int	ret;

	i = 1;
	ret = 0;
	while (i < argc)
	{
		ft_lstadd_back(&stackA, ft_lstnew(ft_atoi_checkint(argv[i])));
		i++;
	}
	ret = ft_checkstackint(stackA);
	return (ret);
}
