/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_points.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 00:51:46 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/24 12:15:52 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	to_points(t_tetris *tetris)
{
	int	i;
	int	j;
	int n;

	n = 0;
	i = 0;
	tetris->points = (t_point *)malloc(sizeof(t_point) * 4);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (n < 4 && tetris->shape[i][j] == 1)
			{
				tetris->points[n].x = i;
				tetris->points[n].y = j;
				n++;
			}
			j++;
		}
		i++;
	}
}
