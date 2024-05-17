/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleal-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:30:42 by joleal-b          #+#    #+#             */
/*   Updated: 2024/05/10 09:26:02 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_signal(int signal)
{
	static unsigned int	bit = 0;
	static unsigned int	c = 0;

	if (signal == SIGUSR2)
	{
		c <<= 1;
		c |= 0b00000000;
	}
	else if (signal == SIGUSR1)
	{
		c <<= 1;
		c |= 0b00000001;
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: [ %d ] \n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_signal);
		signal(SIGUSR2, ft_signal);
	}
	return (0);
}
