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

t_list	*ft_fill_argc(int argc, char **argv, t_list *stack1)
{
	int 	i;
	
	i = 1;
	while (i < argc)
	{
		ft_lstadd_back(&stack1, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return(stack1);
}
