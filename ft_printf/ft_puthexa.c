/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleal-b <joleal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:51:05 by joleal-b          #+#    #+#             */
/*   Updated: 2023/11/13 10:51:09 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_hexa(unsigned int n, int c)
{
	if (n > 15)
	{
		ft_hexa(n / 16, c);
		ft_hexa(n % 16, c);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				ft_putchar(n - 10 + 'a');
			else if (c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

static int	ft_counthexa(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	ft_puthexa(unsigned int n, int c)
{
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	count = ft_counthexa(n);
	ft_hexa(n, c);
	return (count);
}
