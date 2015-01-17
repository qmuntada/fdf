/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:36:16 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/08 15:33:49 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = -1;
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	while (++i < size)
		*(new + i) = '\0';
	return (new);
}
