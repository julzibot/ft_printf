/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jibot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 17:14:40 by jibot             #+#    #+#             */
/*   Updated: 2021/11/04 14:29:19 by jibot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "./printlib/printlib.h"

unsigned int	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		count++;
		i++;
	}
	return (count);
}
