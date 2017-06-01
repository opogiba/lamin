/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:43:48 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/23 12:46:07 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read(int fd)
{
	char	buff[BUFF_SIZE + 1];
	size_t	i;

	if ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		return (ft_strdup(buff));
	}
	else
		return (NULL);
}

static char	*ft_find_n(char *line, t_node *func)
{
	size_t	i;
	char	*tmp;
	int		len;

	i = 0;
	if (func->rest == NULL)
		return (NULL);
	len = (int)ft_strlen(func->rest);
	if (ft_strchr(func->rest, '\n') == NULL)
		return (NULL);
	else
	{
		tmp = func->rest;
		while (func->rest[i] != '\n')
			i++;
		line = ft_strsub(func->rest, 0, i);
		if (func->rest[i + 1] == '\0')
			func->rest = NULL;
		else
			func->rest = ft_strsub(func->rest, i + 1, len - i - 1);
		free(tmp);
	}
	return (line);
}

static char	*ft_do_list(int fd, t_node *func, char *line)
{
	t_node *begin_list;

	begin_list = func;
	while (func && func->fd != fd)
		func = func->next;
	if (!func)
		func = ft_list_get_push_b(begin_list, fd);
	while ((line = ft_find_n(line, func)) == NULL)
	{
		line = ft_read(fd);
		if (line == NULL && func->rest == NULL)
			return (NULL);
		else if (func->rest && line == NULL)
		{
			line = ft_strdup(func->rest);
			free(func->rest);
			func->rest = NULL;
			return (line);
		}
		else if (func->rest && line)
			func->rest = ft_join_free(func->rest, line);
		else
			func->rest = line;
	}
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	static t_node	*begin_list;
	char			*lin;

	lin = NULL;
	if (read(fd, NULL, 0) < 0 || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	if (!begin_list)
		begin_list = ft_lst_get_new(fd);
	if ((*line = ft_do_list(fd, begin_list, lin)) == NULL)
		return (0);
	return (1);
}
