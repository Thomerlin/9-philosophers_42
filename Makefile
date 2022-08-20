# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tyago-ri <tyago-ri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 00:00:11 by tyago-ri          #+#    #+#              #
#    Updated: 2022/08/20 17:18:23 by tyago-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

INC			=	./include/

CC			=	cc
CFLAGS		=	-Werror -Wall -Wextra -I$(INC) -pthread

SRCS		=	$(shell find ./sources -name "*.c")
OBJS		=	$(patsubst %.c,%.o,$(SRCS))

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean		:	
				rm -rf $(OBJS)

fclean		:	clean
				rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re