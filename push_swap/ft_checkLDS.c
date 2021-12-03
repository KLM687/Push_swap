/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkLDS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:02:21 by flee              #+#    #+#             */
/*   Updated: 2021/12/03 13:02:23 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     ft_countLDS(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;
    int     state;
    int     LDS;

    tmp = *stackA;
    i = 0;
    LDS = 0;
    while (i < size)
    {
        state = tmp->state;
        if (state == 1)
            LDS++;
        tmp = tmp->next;
        i++;
    }
    return (LDS);
}

void    ft_resetLDS(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;

    tmp = *stackA;
    i = 0;
    while (i < size)
    {
        if (tmp->state != 1)
        {
            tmp->state = 0;
            tmp = tmp->next;
        }
        i++;
    }
}

t_list    *ft_change_LDSbeacon2(t_list *tmp, t_list *beacon2)
{
    beacon2->state = 0;
    beacon2 = tmp;
    beacon2->state = 2;
    return(tmp);
}

t_list      *ft_set_LDSbeacon2(t_list *tmp, t_list *beacon2)
{
    beacon2 = tmp;
    beacon2->state = 2;
    return (tmp); 
}

void   ft_LDSpart2(t_list *tmp, t_list *beacon1,t_list *beacon2, int grade)
{
    int state;

    tmp = tmp->next;
    state = tmp->state;
    grade = tmp->grade;
    while (state == 0 || state == 1)
    {
        if (beacon2 == NULL && grade > (beacon1->grade) && state != 1)
            beacon2 = ft_set_LDSbeacon2(tmp, beacon2);
        if (beacon2 != NULL && state != 1)
        {
            if (grade < (beacon2->grade) && grade < (beacon1->grade))
                beacon2 = ft_change_LDSbeacon2(tmp, beacon2);
            else if (grade > (beacon2->grade))
            {
                beacon1 = beacon2;
                beacon2 = tmp;
                beacon2->state = 2;
            }
        }
        tmp = tmp->next;
        state = tmp->state;
        grade = tmp->grade;  
    }
}

void    ft_LDS(t_list **stackA, int i)
{
    t_list  *tmp;
    t_list  *beacon1;
    t_list  *beacon2;
    int     grade;
    
    tmp = *stackA;
    grade = tmp->grade;
    while (grade != i)
    {
        tmp = tmp->next;
        grade = tmp->grade;
    }
    if (tmp->state == 0)
    {
        tmp->state = 2;
        beacon1 = tmp;
        beacon2 = NULL;
        ft_LDSpart2(tmp, beacon1, beacon2, grade);
    }
}

void     ft_topLDS(t_list **stackA, int size)
{
    int     i;
    int     memory;
    int     LDS;
    int     maxLDS;

    maxLDS = 0;
    i = 1;
    while (i < size + 1)
    {
        ft_LDS(stackA, i);
        LDS = ft_countLDS(stackA, size);
        if (LDS >= maxLDS)
        {
            maxLDS = LDS;
            memory = i;    
        }
        ft_resetLDS(stackA, size);
        i++;
    }
    ft_LDS(stackA, memory);
}

void      ft_checkLDS(t_list **stackA)
{
    t_list  *tmp;
    int     size;
    int     i;

    tmp = *stackA;
    size = ft_lstsize(*stackA);
    i = 0;
    while (i < size - 1)
    {
        tmp = tmp->next;
        i++;
    }
    tmp->next = *stackA;
    ft_topLDS(stackA, size);
    tmp->next = NULL;
}