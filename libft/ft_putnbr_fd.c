/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 21:02:33 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/07 18:27:34 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		a[10];

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (!n)
		ft_putchar_fd('0', fd);
	while (n)
	{
		*(a + i) = n % 10;
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_putchar_fd(*(a + i) + 48, fd);
	}
}
