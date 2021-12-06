/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushLDS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:28:07 by flee              #+#    #+#             */
/*   Updated: 2021/12/06 13:34:47 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_pushLDS(t_list **stackA, t_list **stackB)
{
    t_list  *tmp;
    int     size;

    tmp = *stackA;
    size = ft_lstsize(*stackA);
    while (size > 0  && tmp)
    {
        tmp = *stackA;
        if ((tmp->state) == 2)
        {
            ft_push(stackA, stackB, 'a');
            tmp = *stackA;
        }
        else        
            ft_rotate(stackA, 'a');
        size--; 
    }
}
