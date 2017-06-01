#include "lem_in.h"

int	ft_min_len(t_func *func)
{
	int i;
	int min;
	int index;

	i = 0;
	index = 0;
	min = func->road[i]->propusk;
	while (func->road[i])
	{
		if (min > func->road[i]->propusk)
		{
			min = func->road[i]->propusk;
			index = i;
		}
		i++;
	}
	return (index);
}

void ft_ants_road(t_func *func)
{
	int i;
	int j;
	int a;

	i = 0;
	j = 0;
	func->m_ants = (t_ants**)malloc(sizeof(t_ants*) * (func->ants + 1));
	while (func->road[i])
	{
		a = func->road[i]->propusk;
		while (a > func->road[i]->mas_len)
		{
			func->m_ants[j] = (t_ants*)malloc(sizeof(t_ants));
			func->m_ants[j]->index_road = i;
			func->m_ants[j]->index_room = 1;
			func->m_ants[j]->nimer = j + 1;
			a--;
			j++;
		}
		i++;
	}
	func->m_ants[j] = NULL;
}
void	ft_ants_name(t_func *func)
{
	int amount;
	int i = 0;
	int j;

	j = 0;
	amount = func->ants;
	while(amount != 0)
	{
		i = 0;
		while (func->road[i])
		{
			if (j != func->ants - 1 && func->road[i]->mas_len != func->road[i]->propusk)
			{
				func->m_ants[j]->nimer = j + 1;
				func->m_ants[j]->index_road = i;
				func->road[i]->propusk--;
				j++;
			}
			i++;
		}
		amount--;
	}
}

void ft_count_ants(t_func *func)
{
	int a;
	int index;
	int i;

	i = 0;
	while (func->road[i])
	{
		func->road[i]->propusk = func->road[i]->mas_len;
		i++;
	}
	a = func->ants;
	while (a != 0)
	{
		index = ft_min_len(func);
		func->road[index]->propusk++;
		a--;
	}
	ft_ants_road(func);
	ft_ants_name(func);
}

