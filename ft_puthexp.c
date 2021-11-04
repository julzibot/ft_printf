/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 18:04:11 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 15:26:19 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

unsigned int	ft_puthexp(unsigned long n, char c)
{
	char				*base;
	unsigned int		count;
	unsigned long		mod;

	count = 2;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (n >= 16)
	{
		mod = n % 16;
		n /= 16;
		ft_puthexp(n, c);
		ft_putchar_fd(base[mod], 1);
		count++;
	}
	else
	{
		ft_putchar_fd(base[n], 1);
		count++;
	}
	return (count);
}
