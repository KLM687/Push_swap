/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:47:50 by flee              #+#    #+#             */
/*   Updated: 2021/09/15 09:47:52 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    ft_handler(int sig)
{
    if (sig == SIGUSR1)
        printf("i get the fucking signal 1\n");
    if (sig == SIGUSR2)
        printf("i get the fucking signal 2\n");
}

int main (void)
{
    struct sigaction sa;
    sigset_t block_mask;

    sa.sa_handler = ft_handler;
    sa.sa_mask = block_mask;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL );
    sigaction(SIGUSR2, &sa, NULL );
    printf("PID = %d\n",getpid());
    printf("waiting\n");
    while(1)
    {
        //printf("waiting\n");
        sleep(1);
    }

}