/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 12:47:33 by opogiba           #+#    #+#             */
/*   Updated: 2017/03/23 12:50:28 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100

# include "../libft.h"

typedef struct		s_node
{
	int				fd;
	char			*rest;
	struct s_node	*next;
}					t_node;

int					get_next_line(const int fd, char **line);
t_node				*ft_lst_get_new(int fd);
t_node				*ft_list_get_push_b(t_node *begin_list, int fd);
#endif
