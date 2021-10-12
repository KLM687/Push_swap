/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argc_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:53:13 by flee              #+#    #+#             */
/*   Updated: 2021/10/12 13:53:15 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_argc_check(int argc, char **argv, t_list *stack1)
{
	int check;
	int check1;

	check = 0;
	check1 = 0;
    	if (argc < 4)
        	return (NULL);
	else
		check = ft_check_digit(argc, argv);
	if (check == 0)
		check1 = ft_check_duplicate(argc, argv);
	if (check == 0 && check1 == 0)
		stack1 = ft_fill_argc(argc, argv, stack1);
	return (stack1);
}
