/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-albe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:07:53 by fde-albe          #+#    #+#             */
/*   Updated: 2022/04/05 16:34:00 by fde-albe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	*binvert(int c)
{
	int	*arraybin;
	int	i;

	i = 7;
	arraybin = malloc(8 * sizeof(int));
	while ((c) != 0)
	{
		arraybin[i] = c % 2;
		c /= 2;
		i--;
	}
	while (i >= 0)
		arraybin[i--] = 0;
	return (arraybin);
}

void	sigsend(int *array,	int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (array[i] == 0)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		else if (array[i] == 1)
		{
			kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	free(array);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;
	int	input;

	if (ac != 3)
	{
		ft_printf("\e[3;1;31m./client [INPUT SERVER PID] [STRING]\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i] != '\0')
	{
		input = ft_isprint((int)(av[2][i]));
		sigsend(binvert(input), pid);
		i++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}
