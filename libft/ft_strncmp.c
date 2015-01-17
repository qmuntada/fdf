/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:48:06 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/08 15:13:01 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	nb;

	nb = 0;
	if (!n)
		return (0);
	while (nb < (n - 1) && *s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
		nb++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
