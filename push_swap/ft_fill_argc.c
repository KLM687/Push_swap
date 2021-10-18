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

t_list	*ft_fill_argc(int argc, char **argv, t_list *stackA)
{
	int 	i;
	t_list	*tmp;
	
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stackA, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	tmp = stackA;
	while (tmp)
	{
		tmp->grade = 0;
		tmp = tmp->next;
	}
	return(stackA);
}
