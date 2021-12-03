# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 11:40:06 by flee              #+#    #+#              #
#    Updated: 2021/11/29 15:44:36 by cesco            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	push_swap

SRC  = push_swap.c \
       ft_lstadd_back.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstlast.c \
       ft_lstnew.c \
       ft_lstsize.c \
       ft_atoi.c \
       ft_itoa.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_isdigit.c \
       ft_argc_check.c \
       ft_check_digit.c \
       ft_check_duplicate.c \
       ft_fill_argc.c \
       ft_swap.c \
       ft_swap_swap.c \
       ft_push.c \
       ft_rotate.c \
       ft_rot_rot.c \
       ft_rev_rotate.c \
       ft_rev_rev.c \
       ft_sort.c \
       ft_sort3.c \
       ft_sort3_sort.c \
       ft_sort5.c \
       ft_sort5_sort.c \
       ft_sort100.c \
       ft_checkLIS.c \
       ft_grade.c \
       ft_check_sort.c \
       ft_lstview.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

OBJS = $(SRC:.c=.o)

all:        $(NAME)

$(NAME):    $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
		/bin/rm -f $(OBJS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
