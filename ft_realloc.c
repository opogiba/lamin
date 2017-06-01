/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:09:01 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:09:07 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char	**realloc_text(t_func *func, char *line)
{
	char	**res;
	int		i;

	i = 0;
	while (func->text && func->text[i])
		i++;
	res = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (func->text && func->text[i])
	{
		res[i] = func->text[i];
		i++;
	}
	res[i] = ft_strdup(line);
	res[++i] = NULL;
	free(func->text);
	return (res);
}

t_room	**realloc_rooms(t_func *func, t_room *new)
{
	t_room	**res;
	int		i;
	int		j;

	i = 0;
	res = (t_room **)malloc(sizeof(t_room *) * (func->count + 2));
	j = func->count;
	func->count++;
	while (j != i)
	{
		res[i] = func->room[i];
		i++;
	}
	res[i] = new;
	res[++i] = NULL;
	free(func->room);
	return (res);
}

t_link	**realloc_links(t_func *func, t_link *new)
{
	t_link	**res;
	int		i;
	int		j;

	j = 0;
	while (func->link && func->link[j])
		j++;
	res = (t_link **)malloc(sizeof(t_link *) * (j + 2));
	i = 0;
	while (i < j)
	{
		res[i] = func->link[i];
		i++;
	}
	res[i] = new;
	res[++i] = NULL;
	free(func->link);
	return (res);
}

int		realloc_road(t_func *func, t_road *new)
{
	int		i;
	t_road	**new_road;

	i = 0;
	while (func->road && func->road[i])
		i++;
	new_road = (t_road **)malloc(sizeof(t_road) * (i + 2));
	i = 0;
	while (func->road && func->road[i])
	{
		new_road[i] = func->road[i];
		i++;
	}
	new_road[i] = new;
	new_road[i + 1] = NULL;
	if (func->road)
		free(func->road);
	func->road = new_road;
	return (i);
}
