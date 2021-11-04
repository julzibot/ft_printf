/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 18:43:43 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 15:04:58 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

static unsigned int	is_negative(int n, int fd)
{
	unsigned int	count;
	
	count = 0;
	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		count += 11;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		count++;
		n = -n;
	}
	return (count);
}

unsigned int	ft_putnbr_fd(int n, int fd)
{
	int				mod;
	unsigned int	count;
	char			c;

	count = is_negative(n, 1);
	if (count == 11)
		return (count);
	else if (n < 0)
		n = -n;
	if (n >= 10)
	{
		mod = (n % 10);
		n /= 10;
		c = mod + '0';
		ft_putnbr_fd(n, fd);
		write (fd, &c, 1);
		count++;
	}
	else if (n < 10 && n >= 0)
	{
		c = n + '0';
		write (fd, &c, 1);
		count++;
	}
	return (count);
}
