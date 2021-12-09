/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 11:32:18 by flee              #+#    #+#             */
/*   Updated: 2021/12/09 14:15:25 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_do_rev_rotate(char *line, t_list **stacka, t_list **stackb)
{
	if (line[2] == 'a' && line[3] == '\n')
		ft_rev_rotate(stacka, 'n');
	else if (line[2] == 'b' && line[3] == '\n')
		ft_rev_rotate(stackb, 'n');
	else if (line[2] == 'r' && line[3] == '\n')
		ft_rev_rev(stacka, stackb, 'n');
	else
		write(1, "Error\n", 6);
}

void	ft_do_rotate(char *line, t_list **stacka, t_list **stackb)
{
	if (line[1] == 'a' && line[2] == '\n')
		ft_rotate(stacka, 'n');
	else if (line[1] == 'b' && line[2] == '\n')
		ft_rotate(stackb, 'n');
	else if (line[1] == 'r' && line[2] == '\n')
		ft_rot_rot(stacka, stackb, 'n');
	else if (line[1] == 'r' && line[2] != '\n')
		ft_do_rev_rotate(line, stacka, stackb);
	else
		write(1, "Error\n", 6);
}

void	ft_do_push(char *line, t_list **stacka, t_list **stackb)
{
	if (line[1] == 'a' && line[2] == '\n')
		ft_push(stackb, stacka, 'n');
	else if (line[1] == 'b' && line[2] == '\n')
		ft_push(stacka, stackb, 'n');
	else
		write(1, "Error\n", 6);
}

void	ft_do_swap(char *line, t_list **stacka, t_list **stackb)
{
	if (line[1] == 'a' && line[2] == '\n')
		ft_swap(stacka, 'n');
	else if (line[1] == 'b' && line[2] == '\n')
		ft_swap(stackb, 'n');
	else if (line[1] == 's' && line[2] == '\n')
		ft_swap_swap(stacka, stackb, 'n');
	else
		write(1, "Error\n", 6);
}
