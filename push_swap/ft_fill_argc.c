/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_argc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:53:52 by flee              #+#    #+#             */
/*   Updated: 2021/10/12 13:53:53 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checkint(t_list *stackA)
{
	t_list *tmp;

	tmp = stackA;
	while (tmp)
	{
		if (tmp->content >= 2147483647 || tmp->content <= -2147483647)
		{
			ft_lstclear(&stackA);
			return (0);
		}
		tmp = tmp->next;
	}
	return(1);
}

t_list	*ft_fill_argc(int argc, char **argv, t_list *stackA)
{
	int i;
	int	ret;
	
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stackA, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ret = ft_checkint(stackA);
	if (ret == 0)
		return (NULL);
	return(stackA);
}
