/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:50:53 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:50:54 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMIN_LEM_IN_H
# define LAMIN_LEM_IN_H
# define INF 2000000000

# include "libft/libft.h"

typedef struct	s_room
{
	char		*room_name;
	int			x_cord;
	int			y_coord;
}				t_room;

typedef struct	s_link
{
	int			link_f;
	int			link_s;
}				t_link;

typedef struct	s_road
{
	int 		propusk;
	int			mas_len;
	int			*mas_road;
}				t_road;

typedef struct	s_ants
{
	int			index_road;
	int 		index_room;
	int 		nimer;
}				t_ants;

typedef struct	s_func
{
	int			fd;
	int			ants;
	int			flag_start;
	int			flag_end;
	int			start_position;
	int			end_position;
	int			count;
	char		**text;
	t_link		**link;
	t_room		**room;
	t_road		**road;
	t_ants		**m_ants;
	int			**matrix;
}				t_func;

void			ft_parsing_comand(t_func *func, char *line);
int				ft_parsing_room(int flag, t_func *func, char *line);
void			ft_amount_ants(t_func *func);
void			ft_error(char *line, t_func *func, int flag);
t_room			**realloc_rooms(t_func *func, t_room *new);
int				ft_check_int(char *line);
char			**realloc_text(t_func *func, char *line);
int				ft_isnbr(char *line);
void			ft_do_new_room(int flag, t_func *func, char *line);
int				ft_parsing_link(t_func *func, char *line);
int				ft_do_links(t_func *func, char *line);
t_link			**realloc_links(t_func *func, t_link *new);
void			ft_do_lamin_str(t_func *func);
void			ft_clean_struct(t_func *func);
int				deikstra_alg(t_func *func);
int				realloc_road(t_func *func, t_road *new);
int				ft_do_road(t_func *func, int len, int *road);
void			do_matrix(t_func *func);
void			ft_clean_matrix(t_func *func, int w);
void			ft_count_ants(t_func *func);
int				ft_go_ants(t_func *func);
void			print_matrix(t_func *in);
void			print_ways(t_func *in, int i);
#endif
