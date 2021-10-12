# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 11:40:06 by flee              #+#    #+#              #
#    Updated: 2021/10/11 12:32:10 by flee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME  =	push_swap

SRC  = push_swap.c \
       ft_split.c \
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

CC = gcc

CFLAGS =

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
