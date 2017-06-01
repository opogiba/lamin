/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:47:11 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/23 12:47:13 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_node	*ft_lst_get_new(int fd)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node)
	{
		new_node->fd = fd;
		new_node->rest = NULL;
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}

t_node	*ft_list_get_push_b(t_node *begin_list, int fd)
{
	t_node *new_list;
	t_node *memory;

	memory = begin_list;
	new_list = ft_lst_get_new(fd);
	while (memory->next)
		memory = memory->next;
	memory->next = new_list;
	return (new_list);
}
