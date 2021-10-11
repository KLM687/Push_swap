/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 10:49:40 by flee              #+#    #+#             */
/*   Updated: 2021/10/11 10:56:55 by flee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int content;
	struct s_stack *next;
}	t_stack;
typedef struct s_control
{
	t_stack *first;
	t_stack *last;
}	t_control;



#endif
