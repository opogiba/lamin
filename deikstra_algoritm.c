/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deikstra_algoritm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:44:26 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:44:28 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_clean_alg(int *min_dist_ex, int *distance, int *road)
{
	if (road)
		free(road);
	if (min_dist_ex)
		free(min_dist_ex);
	if (distance)
		free(distance);
}

int		find_deikstra(t_func *func, int *min_dist_ex, int *distance)
{
	int i;
	int w;
	int vertex;

	i = 0;
	w = INF;
	vertex = -1;
	while (i < func->count)
	{
		if (min_dist_ex[i] == 0 && distance[i] < w)
		{
			vertex = i;
			w = distance[i];
		}
		i++;
	}
	return (vertex);
}

int		find_way(int *min_dist_ex, int *distance, int *road, t_func *func)
{
	int vertex;
	int i;

	vertex = func->start_position;
	while (vertex >= 0 && vertex != func->end_position)
	{
		i = 0;
		while (i < func->count)
		{
			if (func->matrix[vertex][i] == 1
				&& (min_dist_ex[i] == 0
					&&
					distance[i] > distance[vertex] + func->matrix[vertex][i]))
			{
				distance[i] = distance[vertex] + func->matrix[vertex][i];
				road[i] = vertex;
			}
			i++;
		}
		vertex = find_deikstra(func, min_dist_ex, distance);
		if (vertex >= 0)
			min_dist_ex[vertex] = 1;
	}
	return (vertex);
}

void	start_iniz(t_func *func, int *distance, int *min_dist_ex, int *road)
{
	int i;

	i = 0;
	while (i < func->count)
	{
		distance[i] = INF;
		min_dist_ex[i] = 0;
		i++;
	}
	road[func->start_position] = 0;
	distance[func->start_position] = 0;
	min_dist_ex[func->start_position] = 1;
}

int		deikstra_alg(t_func *func)
{
	int *min_dist_ex;
	int *distance;
	int *road;
	int vertex;
	int v;

	min_dist_ex = (int *)malloc(sizeof(int) * func->count);
	distance = (int *)malloc(sizeof(int) * func->count);
	road = (int *)malloc(sizeof(int) * func->count);
	start_iniz(func, distance, min_dist_ex, road);
	vertex = find_way(min_dist_ex, distance, road, func);
	if (vertex == -1)
	{
		ft_clean_alg(min_dist_ex, distance, road);
		return (-1);
	}
	v = ft_do_road(func, distance[func->end_position] + 1, road);
	ft_clean_alg(min_dist_ex, distance, road);
	return (v);
}
