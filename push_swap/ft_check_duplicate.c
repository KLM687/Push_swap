/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_duplicate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:53:34 by flee              #+#    #+#             */
/*   Updated: 2021/12/09 14:12:14 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate2(int *str, int count)
{
	int	a;
	int	b;
	int	dup;

	a = 0;
	while (a < count)
	{
		dup = 0;
		b = 0;
		while (b < count)
		{
			if (str[a] == str[b])
				dup++;
			if (dup > 1)
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}

int	ft_check_duplicate(int argc, char **argv)
{
	int	a;
	int	b;
	int	check;
	int	*str;

	a = 1;
	b = 0;
	check = 0;
	str = (int *)malloc(sizeof(int) * (argc + 1));
	if (str == NULL)
		return (0);
	str[argc] = '\0';
	while (a < argc)
	{
		str[b] = ft_atoi(argv[a]);
		a++;
		b++;
	}
	check = ft_check_duplicate2(str, b);
	free(str);
	return (check);
}
