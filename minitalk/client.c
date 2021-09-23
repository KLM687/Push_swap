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

void     ft_killbinary(int value, pid_t pid)
{
    int nb;
    int power;
    int div;

    nb = 0;
    power = 10000000;
    div = 128;
    while (power > 0)
    {
        nb += (value / div) * power;
        if ((value / div) == 0)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        value = value % div;
        div /= 2;
        power /= 10;
        pause();
    }
}

void    ft_sendprocess(char *str, pid_t pid)
{
        int nb;
        int bi;

        nb = 0;
        while (str[nb] != '\0')
        {
            ft_killbinary(str[nb], pid);
            nb++;
        }    
}

void    ft_handler(int sig)
{
}

int main (int argc, char **argv)
{

    char    *str;
    pid_t   pid;

    str = argv[2];
    //printf("str = %s\n", str);
    pid = ft_atoi(argv[1]);
    //printf("pid = %d\n",pid);
    signal(SIGUSR1, ft_handler);
    if (argc != 3)
    {
        printf("error ./a.out [pid] [message]");
        return (EXIT_FAILURE);
    }
    ft_sendprocess(str, pid);
    return (0);
}