/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:13 by cesco             #+#    #+#             */
/*   Updated: 2021/11/29 16:15:21 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort100(t_list **stackA, t_list **stackB)
{
	*stackB = NULL;
	ft_grade(stackA);
	ft_checkLIS(stackA);
	ft_checkLDS(stackA);
	ft_pushLDS(stackA, stackB);
	ft_pushREST(stackA, stackB);
	//ft_lstview(*stackA);
	//ft_lstview(*stackB);
}

