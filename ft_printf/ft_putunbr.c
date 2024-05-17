/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark <jpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:25:57 by joleal-b          #+#    #+#             */
/*   Updated: 2023/11/11 16:42:15 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
	{
		count += ft_putunbr(n / 10);
		count += ft_putunbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
