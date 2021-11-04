/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:30:31 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 17:42:13 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putnbru_fd(unsigned int n, int fd)
{
	unsigned int	mod;
	static int				count;
	char			c;

	if (n >= 10)
	{
		mod = (n % 10);
		n /= 10;
		c = mod + '0';
		ft_putnbru_fd(n, fd);
		count += ft_putchar_fd(c, fd);
	}
	else if (n < 10 && n >= 0)
	{
		c = n + '0';
		count += ft_putchar_fd(c, fd);
	}
	return (count);
}
