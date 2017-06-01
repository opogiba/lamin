/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:59:42 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:00:46 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	parse_lamin(t_func *func)
{
	char *line;

	while (get_next_line(func->fd, &line) > 0)
	{
		if (line[0] == '#')
			ft_parsing_comand(func, line);
		else if (ft_parsing_room(0, func, line) == 0)
		{
			if (ft_parsing_link(func, line) == 0)
				ft_error(line, func, 2);
			free(line);
			break ;
		}
		free(line);
	}
	while (get_next_line(func->fd, &line) > 0)
	{
		if (ft_parsing_link(func, line) == 0)
		{
			free(line);
			break ;
		}
		free(line);
	}
}

void	parse_road(t_func *func)
{
	int i;
	int a;
	int j;

	a = 0;
	j = 0;
	ft_printf("{red}All ways{eoc}\n");
	while ((i = deikstra_alg(func)) >= 0)
	{
		print_ways(func, j);
		a = 1;
		if (func->road[i]->mas_len == 2)
			break ;
		ft_clean_matrix(func, i);
		j++;
	}
	if (a == 0)
		ft_error(NULL, func, 7);
	ft_printf("\n");
}

int		main(void)
{
	t_func	*func;
	int i;

	i = 0;
	func = (t_func *)malloc(sizeof(t_func));
	ft_do_lamin_str(func);
	ft_amount_ants(func);
	parse_lamin(func);
	if(func->flag_start != 1 && func->end_position != 1)
		ft_error(NULL, func, 8);
	do_matrix(func);
	parse_road(func);
	ft_count_ants(func);
	while (ft_go_ants(func) > 0)
		i++;
	ft_clean_struct(func);
	return (0);
}
