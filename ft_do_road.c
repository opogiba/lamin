/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_road.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:45:19 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:46:09 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_do_road(t_func *func, int len, int *road)
{
	int		i;
	int		*new_road;
	int		tmp;
	t_road	*new;

	new = (t_road*)malloc(sizeof(t_road));
	new->mas_len = len;
	i = func->end_position;
	new_road = (int*)malloc(sizeof(int) * len);
	tmp = 0;
	while (i != func->start_position)
	{
		new_road[tmp] = i;
		i = road[i];
		tmp++;
	}
	new_road[tmp] = func->start_position;
	i = 0;
	while (i < (len / 2))
	{
		ft_swap(&new_road[i], &new_road[len - i - 1]);
		i++;
	}
	new->mas_road = new_road;
	return (realloc_road(func, new));
}
