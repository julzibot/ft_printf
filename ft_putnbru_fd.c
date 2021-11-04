/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:30:31 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 14:30:19 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

unsigned int	ft_putnbru_fd(unsigned int n, int fd)
{
	unsigned int	mod;
	unsigned int	count;
	char			c;

	count = 0;
	if (n >= 10)
	{
		mod = (n % 10);
		n /= 10;
		c = mod + '0';
		ft_putnbru_fd(n, fd);
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
