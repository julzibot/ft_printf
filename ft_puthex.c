/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:52 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 18:29:52 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	vabs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

/*static int	is_negative(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_putstr_fd("-80000000", fd);
	else if (n < 0)
		count += ft_putchar_fd('-', fd);
	return (count);
}*/

int	ft_puthex(unsigned int n, char c)
{
	static int		count;
	char			*base;
	unsigned int	mod;

	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		mod = n % 16;
		n /= 16;
		ft_puthex(n, c);
		count += ft_putchar_fd(base[mod], 1);
	}
	else
		count += ft_putchar_fd(base[(unsigned int)n], 1);
	return (count);
}
