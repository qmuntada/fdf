/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:26:44 by qmuntada          #+#    #+#             */
/*   Updated: 2014/11/08 16:17:28 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = -1;
	news = malloc(sizeof(char) * len);
	if (!news || !len || !s)
		return (NULL);
	while (++i < len)
		*(news + i) = *(s + start + i);
	return (news);
}
