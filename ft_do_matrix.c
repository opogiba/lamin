/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:18:24 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:19:13 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clean_matrix(t_func *func, int w)
{
	int j;
	int i;

	i = 0;
	while (i < func->road[w]->mas_len)
	{
		if (func->road[w]->mas_road[i] != func->start_position &&
			func->road[w]->mas_road[i] != func->end_position)
		{
			j = 0;
			while (j < func->count)
			{
				func->matrix[func->road[w]->mas_road[i]][j] = 0;
				func->matrix[j][func->road[w]->mas_road[i]] = 0;
				j++;
			}
		}
		i++;
	}
}

int		ft_check_link(t_func *func, int f, int s)
{
	int i;

	i = 0;
	while (func->link[i])
	{
		if (func->link[i]->link_f == f && func->link[i]->link_s == s)
			return (1);
		if (func->link[i]->link_f == s && func->link[i]->link_s == f)
			return (1);
		i++;
	}
	return (0);
}

void	do_matrix(t_func *func)
{
	int i;
	int j;

	func->count = 0;
	i = 0;
	while (func->room && func->room[func->count])
		func->count++;
	func->matrix = (int **)malloc(sizeof(int *) * (func->count));
	while (i < func->count)
	{
		j = 0;
		func->matrix[i] = (int *)malloc(sizeof(int) * func->count);
		while (j < func->count)
		{
			func->matrix[i][j] = ft_check_link(func, i, j);
			j++;
		}
		i++;
	}
}
