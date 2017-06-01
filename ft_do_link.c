/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:16:09 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:17:05 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_do_links(t_func *func, char *line)
{
	t_link	*new;
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, '-');
	new = (t_link *)malloc(sizeof(t_link));
	new->link_f = -1;
	new->link_s = -1;
	while (func->room[i])
	{
		if (ft_strequ(tmp[0], func->room[i]->room_name))
			new->link_f = i;
		if (ft_strequ(tmp[1], func->room[i]->room_name))
			new->link_s = i;
		i++;
	}
	ft_clean_two_char(tmp);
	if (new->link_f < 0 || new->link_s < 0)
		return (0);
	func->link = realloc_links(func, new);
	func->text = realloc_text(func, line);
	return (1);
}

int		ft_parsing_link(t_func *func, char *line)
{
	char	**tmp;
	int		i;
	int		a;

	i = 0;
	a = 0;
	tmp = ft_strsplit(line, '-');
	while (tmp[i])
		i++;
	if (i == 2)
	{
		i = 0;
		while (func->room[i])
		{
			if (ft_strequ(tmp[0], func->room[i]->room_name))
				a++;
			if (ft_strequ(tmp[1], func->room[i]->room_name))
				a++;
			i++;
		}
	}
	ft_clean_two_char(tmp);
	if (a == 2)
		return (ft_do_links(func, line));
	return (0);
}
