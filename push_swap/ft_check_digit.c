/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:53:26 by flee              #+#    #+#             */
/*   Updated: 2021/10/12 13:53:27 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_digit(int argc, char	**argv)
{
	int a;
	int b;
	int check;

	a = 1;
	check = 0;
	while(a < argc)
	{
		b = 0;
		while(argv[a][b] != '\0')
		{
			check = ft_isdigit(argv[a][b]);
			if (check == 1)
				return (1);
			b++;
		}
		a++;
	}
	return (0);
}
