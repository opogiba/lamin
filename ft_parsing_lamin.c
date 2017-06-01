/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_lamin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:13:53 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:14:21 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_amount_ants(t_func *func)
{
	char *line;

	get_next_line(func->fd, &line);
	func->ants = ft_check_int(line);
	if (func->ants <= 0)
		ft_error(line, func, 0);
	func->text = (char **)malloc(sizeof(char *) * 2);
	func->text[0] = ft_strdup(line);
	func->text[1] = NULL;
	free(line);
}

void	ft_check_comand(t_func *func, char *line, char *tmp)
{
	if (ft_strequ((line + 2), "start"))
	{
		func->flag_start++;
		get_next_line(func->fd, &line);
		if (line[0] == '#' || ft_parsing_room(1, func, line) == 0)
		{
			free(tmp);
			ft_error(line, func, 4);
		}
		free(line);
	}
	else if (ft_strequ((line + 2), "end"))
	{
		func->flag_end++;
		get_next_line(func->fd, &line);
		if (line[0] == '#' || ft_parsing_room(2, func, line) == 0)
		{
			free(tmp);
			ft_error(line, func, 4);
		}
		free(line);
	}
}

void	ft_parsing_comand(t_func *func, char *line)
{
	char *tmp;

	tmp = line;
	if (line[0] == '#' && line[1] != '#')
		func->text = realloc_text(func, line);
	else if (line[0] == '#' && line[1] == '#')
	{
		func->text = realloc_text(func, line);
		ft_check_comand(func, line, tmp);
		if (func->flag_start > 1 || func->flag_end > 1)
			ft_error(line, func, 1);
	}
}
