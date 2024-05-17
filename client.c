/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleal-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:30:29 by joleal-b          #+#    #+#             */
/*   Updated: 2024/05/10 11:54:40 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_msg(int server_pid, int c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c << bit & 0b10000000)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		bit++;
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	if (ac != 3 || !ft_isstrdigit(av[1]))
		ft_putstr("Error! The input must be → ./client <PID -> Only Numbers> <Message>");
	else if (ft_isstrdigit(av[1]))
	{
		server_pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send_msg(server_pid, av[2][i]);
			i++;
		}
		send_msg(server_pid, '\n');
	}
	return (0);
}
