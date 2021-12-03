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

int     ft_countLIS(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;
    int     state;
    int     LIS;

    tmp = *stackA;
    i = 0;
    LIS = 0;
    while (i < size)
    {
        state = tmp->state;
        if (state == 1)
            LIS++;
        tmp = tmp->next;
        i++;
    }
    return (LIS);
}

void    ft_resetLIS(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;

    tmp = *stackA;
    i = 0;
    while (i < size)
    {
        tmp->state = 0;
        tmp = tmp->next;
        i++;
    }
}

void   ft_LISpart2(t_list *tmp, t_list *beacon1,t_list *beacon2, int grade)
{
    int state;

    tmp = tmp->next;
    state = tmp->state;
    grade = tmp->grade;
    while (state == 0)
    {
        if (beacon2 == NULL && grade > (beacon1->grade))
        {
            beacon2 = tmp;
            beacon2->state = 1;
        }
        if (beacon2 != NULL)
        {
            if (grade < (beacon2->grade) && grade > (beacon1->grade))
            {
                beacon2->state = 0;
                beacon2 = tmp;
                beacon2->state = 1;
            }
            else if (grade > (beacon2->grade) && beacon2)
            {
                beacon1 = beacon2;
                beacon2 = tmp;
                beacon2->state = 1;
            }
        }
        tmp = tmp->next;
        state = tmp->state;
        grade = tmp->grade;  
    }
}

void    ft_LIS(t_list **stackA, int i)
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
    tmp->state = 1;
    beacon1 = tmp;
    beacon2 = NULL;
    printf("beacon1 =%d %d\n",beacon1->grade, beacon1->state);
    ft_LISpart2(tmp, beacon1, beacon2, grade);
}

int     ft_topLIS(t_list **stackA, int size)
{
    int     i;
    int     memory;
    int     LIS;
    int     maxLIS;

    maxLIS = 0;
    i = 1;
    while (i < size + 1)
    {
        ft_LIS(stackA, i);
        LIS = ft_countLIS(stackA, size);
        printf("i = %d LIS =%d\n",i , LIS);
        if (LIS >= maxLIS)
        {
            maxLIS = LIS;
            memory = i;    
        }
        ft_resetLIS(stackA, size);
        i++;
    }
    ft_LIS(stackA, memory);
    return (maxLIS);
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
    dead = ft_topLIS(stackA, size);
    tmp->next = NULL;
    return (dead);
}

int     ft_checktop(t_list **stackA)
{
    int dead;


    ft_lstview(*stackA);
    dead = ft_circle(stackA);
    printf("enter check\n");
    ft_lstview(*stackA);
    return (dead);
}