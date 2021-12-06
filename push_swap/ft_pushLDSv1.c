/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushLDS.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:27:18 by flee              #+#    #+#             */
/*   Updated: 2021/12/06 11:27:19 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_search_movelow(t_list **stackA)
{
    t_list  *tmp;
    int     mv;
    int     mv2;

    mv = 0;
    mv2 = 0;
    tmp = *stackA;
    while (tmp)
    {
        if (tmp->state == 2)
            mv2 = mv;
        tmp = tmp->next;
        mv++;
    }
    return (mv2);
}

int     ft_search_movetop(t_list **stackA)
{
    t_list  *tmp;
    int     mv;

    mv = 0;
    tmp = *stackA;
    while (tmp && tmp->state != 2)
    {
        tmp = tmp->next;
        mv++;
    }
    return (mv);
}

void    ft_pushmove(int mv1, int mv2, t_list **stackA, t_list **stackB)
{
    if (mv1 <= mv2)
    {
        while (mv1 > 0)
        {
            ft_rotate(stackA, 'a');
            mv1--;
        }
    }
    else
        while(mv2 > 0)
        {
            ft_rev_rotate(stackA, 'a');
            mv2--;
        }
    ft_push(stackA, stackB, 'a');
}

int     ft_LDSclear(t_list **stackA)
{
    t_list  *tmp;
    int     end;

    tmp = *stackA;
    end = 1;
    while (tmp)
    {
        if ((tmp->state) == 2)
            end = 0;
        tmp = tmp->next;
    }
    return (end); 
}

void    ft_searchmove(t_list **stackA, t_list **stackB)
{
    int     mv1;
    int     mv2;
    int     size;
    int     end;

    mv1 = ft_search_movetop(stackA);
    mv2 = ft_search_movelow(stackA);
    size = ft_lstsize(*stackA);
    mv2 = size - mv2;
    ft_pushmove(mv1, mv2, stackA, stackB);
    end = ft_LDSclear(stackA);
    if (end == 0)
        ft_searchmove(stackA, stackB);
}

void    ft_pushLDS(t_list **stackA, t_list **stackB)
{
    ft_searchmove(stackA,stackB);
}
