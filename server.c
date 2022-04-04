/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:09:06 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/04 15:57:42 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
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
	char	*str;
	int		cena;

	str = malloc(8 * sizeof(int) + 1);
	if (sinal == 30)
	{
		str[g_i] = '0';
		g_i++;
	}
	else if (sinal == 31)
	{
		str[g_i] = '1';
		g_i++;
	}
	if (g_i == 8)
	{
		str[g_i] = '\0';
		cena = decoder(str);
		printf("%c\n", cena);
		g_i = 0;
	}
	free (str);
}

int	main(void)
{
	printf("\nServer PID: %d\n", getpid());
	signal(SIGUSR1, receive_str);
	signal(SIGUSR2, receive_str);
	while (1)
		;
}
