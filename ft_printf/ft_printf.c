/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joleal-b <joleal-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 09:34:19 by joleal-b          #+#    #+#             */
/*   Updated: 2023/11/13 11:12:30 by joleal-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_checkconversion(va_list ap, char c)
{
	if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(ap, unsigned long)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(ap, unsigned int)));
	else if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(ap, int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), c));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		i;
	va_list	ap;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			count += ft_checkconversion(ap, format[i]);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(ap);
	return (count);
}

/*int		main(void)
{
	char	a;
	char	*str;
	char	*str2;
	char	percent;
	int		i;
	unsigned int	b;
	unsigned int	hex;

	a = 'a';
	str = "ugdygd";
	str2 = "10";
	i = -42174612;
	b = -42174612;
	hex = -10;
	percent = '%';

	// %c
	write(1, "ft_c\n", 5);
	printf("%d\n", printf("%c\n", a));
	printf("%d\n", ft_printf("%c\n", a));
	printf("\n\n");

	// %s
	write(1, "ft_s\n", 5);
	printf("%d\n", printf("%s\n", str));
	printf("%d\n", ft_printf("%s\n", str));
	printf("\n\n");

	// %p
	write(1, "ft_p\n", 5);
	printf("%d\n", printf("%p\n", str2));
	printf("%d\n", ft_printf("%p\n", str2));
	printf("\n\n");
	// %d
	write(1, "ft_d\n", 5);
	printf("%d\n", printf("%d\n", i));
	printf("%d\n", ft_printf("%d\n", i));
	printf("\n\n");

	// %i
	write(1, "ft_i\n", 5);
	printf("%d\n", printf("%i\n", i));
	printf("%d\n", ft_printf("%i\n", i));
	printf("\n\n");

	// %u
	write(1, "ft_u\n", 5);
	printf("%d\n", printf("%u\n", b));
	printf("%d\n", ft_printf("%u\n", b));
	printf("\n\n");

	// %x
	write(1, "ft_x\n", 5);
	printf("%d\n", printf("%x\n", hex));
	printf("%d\n", ft_printf("%x\n", hex));
	printf("\n\n");

	// %X
	write(1, "ft_X\n", 5);
	printf("%d\n", printf("%X\n", hex));
	printf("%d\n", ft_printf("%X\n", hex));
	printf("\n\n");

	// %%
	write(1, "ft_percent\n", 12);
	printf("%d\n", printf("%%\n"));
	printf("%d\n", ft_printf("%%\n", percent));
	printf("\n\n");
}*/
