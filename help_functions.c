/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:05:56 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:06:36 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_int(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
		return (ft_atoi(line));
	return (-1);
}

int		ft_isnbr(char *line)
{
	int i;

	i = 0;
	if (line[0] == '-')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (i == (int)ft_strlen(line))
		return (1);
	return (0);
}

void	ft_do_lamin_str(t_func *func)
{
	func->fd = 0;
	func->flag_start = 0;
	func->flag_end = 0;
	func->count = 0;
	func->room = NULL;
	func->text = NULL;
	func->link = NULL;
	func->road = NULL;
	func->matrix = NULL;
}

void	ft_claean_continue(t_func *func)
{
	int i;

	i = 0;
	if (func->matrix)
		free(func->matrix);
	if (func->room)
		free(func->room);
	while (func->text && func->text[i])
	{
		free(func->text[i]);
		i++;
	}
	if (func->text)
		free(func->text);
	i = 0;
	while (func->road && func->road[i])
	{
		free(func->road[i]->mas_road);
		free(func->road[i]);
		i++;
	}
	if (func->road)
		free(func->road);
}

void	ft_clean_struct(t_func *func)
{
	int i;

	i = 0;
	while (func->link && func->link[i])
	{
		free(func->link[i]);
		i++;
	}
	if (func->link)
		free(func->link);
	i = 0;
	while (func->room && func->room[i])
	{
		free(func->room[i]->room_name);
		free(func->room[i]);
		i++;
	}
	i = 0;
	while (i < func->count)
	{
		free(func->matrix[i]);
		i++;
	}
	ft_claean_continue(func);
	free(func);
}
