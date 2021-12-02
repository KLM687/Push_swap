/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesco <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:24:39 by cesco             #+#    #+#             */
/*   Updated: 2021/12/01 16:24:40 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_searchfollow(t_list **stackA, int i, int size)
{
    t_list  *tmp;
    int     follow;

    *tmp = *stackA;

}

void    ft_resetfollow(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;

    tmp = *stackA;
    i = 0;
    while (i < size)
    {
        tmp->state = 0;
        tmp =tmp->next;
        i++;
    }
}

int     ft_topfollow(t_list **stackA, int size, int i, int max)
{
    t_list *tmp;

    tmp = *stackA;
    while (i < size + 1)
    {
        while ( )

    }
}

int     ft_circle(t_list **stackA)
{
    t_list  *tmp;
    int     size;
    int     i;
    int     dead;

    tmp = *stackA;
    size = ft_lstsize(*stackA);
    i = 0;
    while (i < size - 1)
    {
        tmp = tmp->next;
        i++;
    }
    tmp->next = *stackA;
    dead = ft_topfollow(stackA, size);
    tmp->next = NULL;
    return (dead);
}

int     ft_checktop(t_list **stackA)
{
    int dead;

    dead = ft_circle(stackA);
    ft_lstview(*stackA);
    return (dead);
}