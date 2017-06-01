/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:21:35 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:22:23 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_room(char **tmp, t_func *func)
{
	int i;
	int a;
	int b;

	i = 0;
	a = ft_check_int(tmp[1]);
	b = ft_check_int(tmp[2]);
	while (func->room && func->room[i])
	{
		if (ft_strequ(tmp[0], func->room[i]->room_name))
		{
			ft_clean_two_char(tmp);
			return (0);
		}
		if (a == func->room[i]->x_cord && b == func->room[i]->y_coord)
		{
			ft_clean_two_char(tmp);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_do_new_room(int flag, t_func *func, char *line)
{
	t_room	*new;
	char	**tmp;

	new = (t_room *)malloc(sizeof(t_room));
	if (flag == 1)
		func->start_position = func->count;
	if (flag == 2)
		func->end_position = func->count;
	tmp = ft_strsplit(line, ' ');
	new->room_name = ft_strdup(tmp[0]);
	new->x_cord = ft_check_int(tmp[1]);
	new->y_coord = ft_check_int(tmp[2]);
	func->room = realloc_rooms(func, new);
	ft_clean_two_char(tmp);
}

int		ft_parsing_room(int flag, t_func *func, char *line)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[i])
		i++;
	if (i == 3 && ft_isnbr(tmp[1]) && ft_isnbr(tmp[2]))
	{
		if (tmp[0][0] == 'L')
			ft_error(line, func, 3);
		if (ft_check_room(tmp, func) == 0)
			ft_error(line, func, 6);
		ft_do_new_room(flag, func, line);
		func->text = realloc_text(func, line);
		ft_clean_two_char(tmp);
		return (1);
	}
	else
	{
		ft_clean_two_char(tmp);
		return (0);
	}
}
