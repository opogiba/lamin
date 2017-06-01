/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opogiba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 14:17:43 by opogiba           #+#    #+#             */
/*   Updated: 2017/04/02 14:17:47 by opogiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_error(char *line, t_func *func, int flag)
{
	if (line)
		free(line);
	ft_clean_struct(func);
	if (flag == 0)
		ft_printf("WRONG AMOUNT OF ANTS\n");
	if (flag == 2)
		ft_printf("NOT EXISTING LINKS\n");
	if (flag == 1)
		ft_printf("WRONG AMOUNT OF COMANDS\n");
	if (flag == 3)
		ft_printf("INVALID NAME OF ROOM\n");
	if (flag == 4)
		ft_printf("AFTER COMAND MUST BE ROOM\n");
	if (flag == 5)
		ft_printf("HAVEN'T LINKS\n");
	if (flag == 6)
		ft_printf("This room exsist\n");
	if (flag == 7)
		ft_printf("HAVENT WAYS\n");
	if (flag == 8)
		ft_printf("HAVEN'T COMMAND\n");
	exit(0);
}
