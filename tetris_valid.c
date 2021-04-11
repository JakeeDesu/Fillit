/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 20:39:11 by hmhindat          #+#    #+#             */
/*   Updated: 2018/11/25 09:46:19 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		v_point(t_point t, t_point *points, int *tested)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (tested[i] && (t.y == points[i].y))
		{
			if ((t.x + 1) == points[i].x)
				return (1);
			if ((t.x - 1) == points[i].x)
				return (1);
		}
		if (tested[i] && (t.x == points[i].x))
		{
			if ((t.y + 1) == points[i].y)
				return (1);
			if ((t.y - 1) == points[i].y)
				return (1);
		}
		i++;
	}
	return (0);
}

void	init_table(int *tested)
{
	int i;

	i = 0;
	while (i < 4)
	{
		tested[i] = 1;
		i++;
	}
}

int		tetris_valid(t_point *points)
{
	int tested[4];
	int i[2];

	i[1] = 0;
	i[0] = 0;
	init_table(tested);
	while (i[0] < 3)
	{
		tested[i[0]] = 0;
		if (v_point(points[i[0]], points, tested))
		{
			while (i[1] > 0 && i[1]--)
				i[0]++;
			i[0]++;
		}
		else
		{
			if (i[0] != 0 && i[0]--)
				i[1]++;
			else
				return (0);
		}
	}
	return (1);
}
