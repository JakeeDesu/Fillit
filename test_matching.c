/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matching.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 07:56:21 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/24 12:14:00 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	test_matching(t_map *a, t_tetris *b, int x, int y)
{
	int	k;

	k = 0;
	while (k < 4)
	{
		if ((x + b->points[k].x >= a->dim[0])
				|| (y + b->points[k].y >= a->dim[0]))
			return (0);
		if ((int)(a->shape[x + b->points[k].x][y + b->points[k].y]) != '.')
			return (0);
		k++;
	}
	return (1);
}
