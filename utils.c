/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpark <jpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:52:07 by joleal-b          #+#    #+#             */
/*   Updated: 2024/05/09 11:28:29 by jpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isstrdigit(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		if ((str[i] > 47 && str[i] < 58) == 1)
			res = 1;
		else
			return (0);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			sign = sign * -1;
		}
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = ((res * 10) + (str[i] - 48));
		i++;
	}
	return (res * sign);
}
