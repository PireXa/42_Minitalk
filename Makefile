# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 14:17:46 by fde-albe          #+#    #+#              #
#    Updated: 2022/04/05 16:10:39 by fde-albe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS		=	server.c ft_recursive_power.c libftprintf.a \

CLIENT_SRCS		=	client.c ft_atoi.c ft_isprint.c libftprintf.a \

RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

SERVER		= server

CLIENT		= client

all:		$(SERVER) $(CLIENT)
			@printf "\e[2;1;92m  🍤 🦓 PireXa Makefiles 🦓 🍤 \e[0m\n"

$(SERVER):	$(SERVER_SRCS)
			@$(CC) -o $(SERVER) $(SERVER_SRCS)
			@printf "\e[105m                                              \e[0m\n"
			@printf "\e[94m#######\e[0m\e[3;1;32m⛩   Successfully Built Server 🍣\e[0m\e[94m#######\e[0m\n"

$(CLIENT):	$(CLIENT_SRCS)
			@$(CC) -o $(CLIENT) $(CLIENT_SRCS)
			@printf "\e[105m                                              \e[0m\n"
			@printf "\e[94m#######\e[0m\e[0m\e[3;1;32m⛩   Successfully Built Client 🥢\e[0m\e[94m#######\e[0m\n"
			@printf "\e[105m                                              \e[0m\n"

clean:
			@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)

fclean:		clean
			@$(RM) $(SERVER) $(CLIENT)
			@printf "\e[94m###########\e[0m\e[3;1;31m🥒 Files Removed 📄 ➡️  🗑 \e[0m\e[94m##########\e[0m\n"

re:			fclean $(SERVER) $(CLIENT)
