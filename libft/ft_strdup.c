/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:44:18 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/08 19:03:44 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*c;
	int		len;

	len = -1;
	while (s1[++len])
		;
	c = (char *)malloc(len * sizeof(char) + 1);
	if (c != NULL)
		ft_strcpy(c, s1);
	*(c + len) = '\0';
	return (c);
}
