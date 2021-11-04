/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 19:03:52 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 15:04:53 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

static unsigned int is_negative(int n, int fd)
{
	unsigned int 	count;

	count = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-80000000", fd);
		count += 9;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', 1);
		count++;
	}
	return (count);
}

unsigned int	ft_puthex(int n, char c)
{
	unsigned int	count;
	char			*base;
	int				mod;

	count = is_negative(n, 1);
	if (n < 0)
		n = -n;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		mod = n % 16;
		n /= 16;
		ft_puthex(n, c);
		ft_putchar_fd(base[mod], 1);
		count++;
	}
	else
		ft_putchar_fd(base[n], 1);
	return (count);
}
