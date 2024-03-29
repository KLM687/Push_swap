/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:27:45 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 12:50:45 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort5(t_list **stackA, t_list **stackB)
{
	ft_grade(stackA);
	ft_sort5_sort(stackA, stackB);
}
