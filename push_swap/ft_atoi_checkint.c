/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_checkint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:35:43 by flee              #+#    #+#             */
/*   Updated: 2021/12/08 09:47:55 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkresult(int result, int i)
{
	int	count;

	count = 0;
	if (result < 0)
		count = 1;
	if (result != 0)
	{
		while (result != 0)
		{
			result /= 10;
			count++;
		}
		if (count != i)
			return (0);
	}
	return (1);
}

int	ft_atoi_checkint(char *str)
{
	int			i;
	long int	result;
	long int	sign;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result *= sign;
	result = ft_checkresult(result, i);
	return ((long)(result));
}
