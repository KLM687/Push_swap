/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort100.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:45:13 by cesco             #+#    #+#             */
/*   Updated: 2021/12/08 12:51:20 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort100(t_list **stackA, t_list **stackB)
{
	*stackB = NULL;
	ft_grade(stackA);
	ft_checklis(stackA);
	ft_pushlds(stackA, stackB);
	ft_pushback(stackA, stackB);
	ft_makeclean(stackA);
}
