#include "lem_in.h"

void    print_ways(t_func *in, int i)
{
	int    j;

	if (in->road && in->road[i])
	{
		j = 0;
		while (j < in->road[i]->mas_len)
		{
			ft_printf("%d ", in->road[i]->mas_road[j]);
			j++;
		}
		ft_printf("\n");
	}
}