/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleal-b <joleal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:11:55 by joleal-b          #+#    #+#             */
/*   Updated: 2023/11/13 10:39:44 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_countptr(unsigned long n)
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

void	ft_pptr(unsigned long n)
{
	if (n > 15)
	{
		ft_pptr(n / 16);
		ft_pptr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_putptr(unsigned long n)
{
	int	count;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	count = 2;
	if (n == 0)
	{
		count += ft_putchar('0');
	}
	else
	{
		ft_pptr(n);
		count += ft_countptr(n);
	}
	return (count);
}
