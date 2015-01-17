/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:18:35 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/04 19:25:24 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c1;
	const char	*c2;

	c2 = src;
	c1 = dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	c2 += len;
	c1 += len;
	while (len--)
		*--c1 = *--c2;
	return (dst);
}
