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

int     ft_count_dead(t_list **stackA)
{
    t_list *tmp;
    int dead;
    int state;

    tmp = *stackA;
    dead = 0;
    while (tmp)
    {
        state = tmp->state;
        if (state == -1)
            dead++;
        tmp = tmp->next;
    }
    return (dead);
}

int     ft_checkend(t_list **stackA)
{
    t_list  *tmp;
    int     end;
    int     state;

    tmp = *stackA;
    end = 0;
    while (tmp && end == 0)
    {
        state = tmp->state;
        if (state == 0)
            end = 1;
        tmp = tmp->next;
    }
    return (end);
}

int     ft_check_state(int grade0, int grade1, t_list **stackA)
{
    t_list  *tmp;
    int     check;
    int     grade;
    int     state;

    check = 1;
    while (grade0 != grade1 && check)
    {
        grade0++;
        tmp = *stackA;
        grade = tmp->grade;
        while (grade != grade0 && check)
        {
            printf("grade = %d grade0 = %d grade1 = %d\n",grade ,grade0, grade1);
            tmp = tmp->next;
            grade = tmp->grade;
            state = tmp->state;
            if (state == 0)
                check = 0;
        }
    }
    if (check == 0)
        tmp->state = -1;
    else
        tmp->state = 1;
    return (check);
}

void    ft_kill(t_list **stackA, t_list *tmp)
{
    int end;
    int grade0;
    int grade1;
    int check;
    int state;

    end = 1;
    grade0 = 1;
    check = 0;
    while (end)
    {
        if (tmp == NULL)
            tmp = *stackA;
        grade1 = tmp->grade;
        state = tmp->state;
        if (grade1 > grade0 && state != -1)
        {
            check = ft_check_state(grade0, grade1, stackA);
            if (check == 1)
                grade0 = grade1;
        }
        tmp = tmp->next;
        end = ft_checkend(stackA);
        ft_lstview(*stackA);
    }
}

int     ft_checktop(t_list **stackA)
{
    t_list *tmp;
    int grade;
    int dead;

    tmp = *stackA;
    grade = tmp->grade;
    while (grade != 1)
    {
        tmp = tmp->next;
        grade = tmp->grade;
    }
    tmp->state = 1;
    ft_kill(stackA, tmp->next);
    dead = ft_count_dead(stackA); 
    return (dead);
}