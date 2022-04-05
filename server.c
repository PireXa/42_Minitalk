/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:09:06 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/05 17:19:35 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	g_i = 0;

int	decoder(char *str)
{
	int	a;
	int	res;

	a = 7;
	res = 0;
	while (a >= 0)
	{
		if (str[a] == '1')
			res += 1 * ft_recursive_power(2, (7 - a));
		a--;
	}
	return (res);
}

void	receive_str(int sinal)
{
	char	str[9];
	int		cena;

	if (sinal == 30)
		str[g_i++] = '0';
	else if (sinal == 31)
		str[g_i++] = '1';
	if (g_i == 8)
	{
		str[g_i] = '\0';
		if (str[0] == '1')
		{
			g_i = write(1, "\n", 1) - 1;
			return ;
		}
		cena = decoder(str);
		ft_printf("\e[3;1;35m%c\e[0m", cena);
		g_i = 0;
	}
}

int	main(void)
{
	ft_printf("\n\e[3;1;34mServer PID: %d\e[0m\n", getpid());
	signal(SIGUSR1, receive_str);
	signal(SIGUSR2, receive_str);
	while (1)
		;
}
