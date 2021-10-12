/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 12:04:45 by flee              #+#    #+#             */
/*   Updated: 2021/06/10 17:58:13 by cesco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	ft_isdigit (int character)
{
	char	*str;
	int		i;

	str = ft_itoa(character);
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && 
				(str[i] != '-' || str[i] != '+'))
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}
