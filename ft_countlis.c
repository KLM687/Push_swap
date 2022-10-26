/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countLIS.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:26:23 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 11:47:08 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countlis(t_list **stackA, int size)
{
	t_list	*tmp;
	int		i;
	int		state;
	int		lis;

	tmp = *stackA;
	i = 0;
	lis = 0;
	while (i < size)
	{
		state = tmp->state;
		if (state == 1)
			lis++;
		tmp = tmp->next;
		i++;
	}
	return (lis);
}

void	ft_resetlis(t_list **stackA, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stackA;
	i = 0;
	while (i < size)
	{
		tmp->state = 0;
		tmp = tmp->next;
		i++;
	}
}

t_list	*ft_change_beacon2(t_list *tmp, t_list *beacon2)
{
	beacon2->state = 0;
	beacon2 = tmp;
	beacon2->state = 1;
	return (tmp);
}

t_list	*ft_set_beacon2(t_list *tmp, t_list *beacon2)
{
	beacon2 = tmp;
	beacon2->state = 1;
	return (tmp);
}
