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

int     ft_count_dead(t_list **stackA, int size)
{
    t_list  *tmp;
    int     i;
    int     dead;
    int     state;

    tmp = *stackA;
    i = 0;
    dead = 0;
    while (i < size)
    {
        state = tmp->state;
        if (state == 1)
            dead++;
        tmp = tmp->next;
        i++;
    }
    return (dead);
}


int     ft_kill2(t_list *tmp, int i, int grade, int grade1)
{

    if (grade1 == i)
        return (0);
    else if (grade1 != grade)
        tmp->state = 1;
    else if (grade1 == grade)
        grade += 1;
    return (grade);
}

void    ft_kill(t_list **stackA, int i)
{
    t_list  *tmp;
    int     grade;
    int     grade1;
    int     count;

    tmp = *stackA;
    count = 2;
    printf("i = %d\n", i);
    while (count)
    {
        grade = tmp->grade;
        if (grade == i)
        {
            grade++;
            while (grade > 0)
            {  
                tmp = tmp->next;
                grade1 = tmp->grade;
                grade = ft_kill2(tmp, i, grade, grade1);
            }
            count = 0;
        }
        tmp = tmp->next;
    }
}

void    ft_resetdead(t_list **stackA, int size)
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

int     ft_brainkill(t_list **stackA, int size)
{
    int i;
    int i2;
    int dead;
    int dead2;

    i = 1;
    dead2 = 99999;
    while (i < size + 1)
    {
        ft_kill(stackA, i);
        dead = ft_count_dead(stackA, size);
        printf("dead = %d i = %d\n", dead, i);
        if (dead < dead2)
        {
            dead2 = dead;
            i2 = i;
            printf("dead = %d i2 =%d\n", dead, i2);
        }
        ft_resetdead(stackA, size);
        i++;
    }
    ft_kill(stackA, i2);
    return (dead2);
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
    dead = ft_brainkill(stackA, size);
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