
#include "lem_in.h"

int		ft_check_ant_room(t_func *func, int i)
{
	int j;

	j = 0;
	if(func->m_ants[i]->index_room < 0)
		return (0);
	while (func->m_ants[j])
	{
		if(func->m_ants[j]->index_road == func->m_ants[i]->index_road)
		{
			if (func->m_ants[j]->index_room == func->m_ants[i]->index_room + 1)
				return (0);
		}
		j++;
	}
	return (1);
}

int		ft_go_ants(t_func *func)
{
	int i;
	int e;
	char *str;

	i = 0;
	e = 0;
	while (i < func->ants)
	{
		if (ft_check_ant_room(func, i))
		{
			if (e != 0)
				ft_printf(" ");
			str = func->room[func->road[func->m_ants[i]->index_road]->
					mas_road[func->m_ants[i]->index_room]]->room_name;
			ft_printf("L%d-%s",func->m_ants[i]->nimer, str);
			func->m_ants[i]->index_room++;
			if (func->m_ants[i]->index_room >=
				func->road[func->m_ants[i]->index_road]->mas_len)
				func->m_ants[i]->index_room = -1;
			e = 1;
		}
		i++;
	}
	ft_printf("\n");
	return (e);
}