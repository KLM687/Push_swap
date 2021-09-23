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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <signal.h> 
#include <sys/types.h> 
#include <time.h>
#include "minitalk.h"

static char     bi;

int     ft_convdec(int value)
{
    int pow;
    int dec;
    int modulo;

    pow = 1;
    dec = 0;
    modulo = 0;
    while (value > 0)
    {
        modulo = value % 10;
        if (modulo == 1)
            dec += pow;
        value /= 10;
        pow *= 2;
    }
    return (dec);
}

void    ft_conv(char *str)
{
    int     dec;
    char    c;
    
    dec = ft_atoi(str);
    c = ft_convdec(dec);
    write(1, &c, 1);
}

void   ft_handler(int sig, siginfo_t *info, void *secret)
{
    if (sig == SIGUSR1)
        bi = '0';
    if (sig == SIGUSR2)
        bi = '1';
    kill((info->si_pid), SIGUSR1);
}

int     ft_fill(char *str, int nb)
{
    str[nb] = bi;
    nb++;
    if (nb == 8)
    {
        ft_conv(str);
        nb = 0;
    }
    return (nb);
}

int main (void)
{
    char    *str;
    int     nb;
    struct sigaction sa;

    nb = 0;
    sa.sa_sigaction = ft_handler;
    sa.sa_flags = SA_RESTART | SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL );
    sigaction(SIGUSR2, &sa, NULL );
    printf("PID = %d\n",getpid());
    str = malloc(sizeof(int) * 8);
    if (!str)
    {
        free(str);
        return (EXIT_FAILURE);
    }
    while(1)
    {
        pause();
        nb = ft_fill(str, nb);
    }
}