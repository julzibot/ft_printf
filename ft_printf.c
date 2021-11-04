/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:42:23 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 15:27:03 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

static unsigned int	ft_putform(va_list ap, char flag)
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
		return (ft_puthex(va_arg(ap, int), flag));
	else if (flag == 'u')
		return (ft_putnbru_fd(va_arg(ap, unsigned int), 1));
	else if (flag == '%')
		return (ft_putchar_fd('%', 1));
	return (0);
}


int	ft_printf(const char *format, ...)
{
	unsigned int	i;
	unsigned int	count;
	va_list			ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_putform(ap, format[i + 1]);
		else if (format[i - 1] != '%')
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
