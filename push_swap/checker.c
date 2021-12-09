/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 10:21:50 by flee              #+#    #+#             */
/*   Updated: 2021/12/09 14:04:34 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_read_command(char *line, t_list **stacka, t_list **stackb)
{
	if (line[0] == 's')
		ft_do_swap(line, stacka, stackb);
	else if (line[0] == 'p')
		ft_do_push(line, stacka, stackb);
	else if (line[0] == 'r')
		ft_do_rotate(line, stacka, stackb);
	else
		write(1, "Error\n", 6);
}

void	ft_get_command(t_list **stacka, t_list **stackb)
{
	int		sort;
	char	*line;

	sort = 0;
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
			break ;
		ft_read_command(line, stacka, stackb);
		free(line);
	}
	if (*stackb == NULL)
		sort = ft_check_sort(stacka);
	if (sort == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	stacka = NULL;
	stackb = NULL;
	stacka = ft_argc_check(argc, argv, stacka);
	if (stacka == NULL)
		return (EXIT_FAILURE);
	ft_get_command(&stacka, &stackb);
	if (stacka != NULL)
		ft_lstclear(&stacka);
	if (stackb != NULL)
	{
		ft_lstclear(&stackb);
	}
	return (EXIT_SUCCESS);
}
