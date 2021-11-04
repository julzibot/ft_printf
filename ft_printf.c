/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:42:23 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 19:39:44 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putform(va_list ap, char flag)
{
	if (flag == 'c')
		return (ft_putchar_fd(va_arg(ap, int), 1));
	else if (flag == 's')
		return (ft_putstr_fd(va_arg(ap, char *), 1));
	else if (flag == 'i' || flag == 'd')
		return (ft_putnbr_fd(va_arg(ap, int), 1));
	else if (flag == 'p')
	{
		write(1, "0x", 2);
		return (ft_puthexp(va_arg(ap, unsigned long), 'x'));
	}
	else if (flag == 'x' || flag == 'X')
		return (ft_puthex(va_arg(ap, unsigned int), flag));
	else if (flag == 'u')
		return (ft_putnbru_fd(va_arg(ap, unsigned int), 1));
	else
		return (0);
}


int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	va_list			ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%' && format[i - 1] != '%')
				count += ft_putchar_fd('%', 1);
			else if (format[i + 1] == '%' && format[i - 1] == '%' && format[i - 2] == '%')
				count += ft_putchar_fd('%', 1);
			else
				count += ft_putform(ap, format[i + 1]);
		}
		else if (format[i - 1] != '%')
			count += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}
