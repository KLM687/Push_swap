/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:48:00 by flee              #+#    #+#             */
/*   Updated: 2021/09/15 09:48:02 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (int argv, char **argc)
{
    char *mem;

    if (argv != 3)
    {
        printf("error ./a.out [pid] [message]");
        return (EXIT_FAILURE);
    }
    mem = (int)malloc(sizeof(int) * 8);
    if (!mem)
    {
        mem = NULL;
        return (EXIT_FAILURE);
    }
    mem = ft_atoibase(argc[2]);

    //kill(ft_atoi(argc[1]),SIGUSR2);
    return (0);
}