/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:04:03 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/07 18:57:11 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlins(char **line, t_list *bs, int nb)
{
	int		cpt;
	t_list	*list;

	cpt = -1;
	list = bs;
	while (++cpt < nb)
	{
		*line = ft_strjoin(*line, list->content);
		list = list->next;
	}
	*(*line + (ft_strlen(*line) - 1)) = '\0';
}

int		save_line(char *buf, t_list **bs)
{
	int		pos;
	int		nb;

	nb = 0;
	pos = ft_strcf(buf, '\n');
	if (pos != -1 && *buf)
	{
		ft_lstpushback(*&bs, buf, pos + 1);
		buf += (pos + 1);
		while (*buf)
		{
			pos = ft_strcf(buf, '\n');
			if (pos == -1)
				pos = ft_strlen(buf);
			ft_lstpushback(*&bs, buf, pos + 1);
			buf += (pos + 1);
			nb++;
		}
		return (nb);
	}
	else
		ft_lstpushback(*&bs, buf, BUFF_SIZE);
	return (-1);
}

int		check_list(t_list **list, int *eolf)
{
	int		nb_mal;
	t_list	*lst_tmp;
	char	*str;

	*eolf = 0;
	nb_mal = 0;
	lst_tmp = *list;
	if (!lst_tmp)
		return (-1);
	while (lst_tmp)
	{
		str = lst_tmp->content;
		if ((*eolf = *(str + lst_tmp->content_size - 1)) == '\n')
			return (nb_mal);
		else
		{
			nb_mal++;
			lst_tmp = lst_tmp->next;
		}
	}
	return (nb_mal);
}

char	*ft_read(int fd, t_list **buf_save, int *res, char *line)
{
	int		nb;
	char	*buf;

	buf = malloc(sizeof(char) * BUFF_SIZE + 1);
	while ((*res = read(fd, buf, BUFF_SIZE)))
	{
		buf[BUFF_SIZE] = '\0';
		if (*res <= 0)
			return (NULL);
		nb = save_line(buf, *&buf_save);
		if (ft_strcf(buf, '\n') != -1)
		{
			nb = ft_lstlen(*buf_save) - nb;
			line = malloc(sizeof(char) * (BUFF_SIZE * nb));
			ft_putlins(&line, *buf_save, nb);
			*buf_save = ft_lstnclear(*&buf_save, nb);
			return (line);
		}
		ft_strclr(buf);
	}
	return (NULL);
}

int		get_next_line(int fd, char **line)
{
	static t_list	*buf_save;
	int				nb;
	int				eol_found;
	int				cpt;
	int				res;

	cpt = -1;
	if ((nb = check_list(&buf_save, &eol_found)) >= 0)
		if (eol_found)
		{
			*line = malloc(sizeof(char) * (nb * BUFF_SIZE));
			while (++cpt <= nb && buf_save)
			{
				*line = ft_strjoin(*line, buf_save->content);
				buf_save = buf_save->next;
			}
			*(*line + (ft_strlen(*line) - 1)) = '\0';
			return (1);
		}
	*line = ft_read(fd, &buf_save, &res, *line);
	if (res <= 0)
		return (res);
	return (1);
}
