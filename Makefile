# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:17:46 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/04 15:29:28 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS		=	server.c ft_recursive_power.c \

CLIENT_SRCS		=	client.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \

SERVER_OBJS		= $(SERVER_SRCS:.c=.o)

CLIENT_OBJS		= $(CLIENT_SRCS:.c=.o)

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -I.

SERVER		= server.out

CLIENT		= client.out

all:		$(SERVER) $(CLIENT)

$(SERVER):	$(SERVER_OBJS)
			gcc -o $(SERVER) $(SERVER_OBJS)

$(CLIENT):	$(CLIENT_OBJS)
			gcc -o $(CLIENT) $(CLIENT_OBJS)

clean:
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

re:			fclean $(SERVER) $(CLIENT) clean
