/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmuntada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 16:23:45 by qmuntada          #+#    #+#             */
/*   Updated: 2015/01/17 16:19:46 by qmuntada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*get_lstfile(int fd, int **len)
{
	char	*line;
	t_list	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		**len = ft_strlen(line);
		ft_lstpushback(&list, line, ft_strlen(line));
	}
	return (list);
}

int		ft_tablen(char **array)
{
	int		x;

	x = 0;
	while (*(array + x))
		x++;
	return (x);
}

int		*put_array(char **line, int **len)
{
	int		i;
	int		y;
	int		*valueline;

	i = -1;
	y = ft_tablen(line);
	if (y < **len)
		**len = y;
	valueline = malloc(sizeof(int) * y);
	while (++i < y)
		valueline[i] = ft_atoi(line[i]);
	return (valueline);
}

int		**get_array(int fd, int *len, int *wid)
{
	int		**array;
	char	**line;
	t_list	*list;
	int		x;

	x = -1;
	list = get_lstfile(fd, &len);
	if (!list)
		exit(0);
	array = malloc(sizeof(int *) * ft_lstlen(list));
	while (list)
	{
		line = ft_strsplit(list->content, ' ');
		array[++x] = put_array(line, &len);
		list = list->next;
	}
	*wid = x + 1;
	return (array);
}

int		main(int ac, char **av)
{
	int		fd;
	int		**array;
	int		len;
	int		wid;
	int		**color;

	len = 0;
	wid = 0;
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (0);
		array = get_array(fd, &len, &wid);
		close(fd);
		color = getcolor(av, ac);
		if (array)
			display_tab(array, len, wid, color);
		return (0);
	}
	return (-1);
}
