/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 02:40:40 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/24 12:10:48 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	update_cord(int *cord, int dim)
{
	(cord[1])++;
	if (cord[1] >= dim)
	{
		cord[1] = 0;
		(cord[0])++;
	}
	if (cord[0] >= dim)
	{
		cord[0] = 0;
		cord[1] = 0;
	}
}

int		check_all(t_map *a, t_tetris *b, int dim)
{
	if (b->x == 1)
		update_cord(b->cord, dim);
	else
		b->x = 1;
	while (b->cord[0] < dim)
	{
		if (test_matching(a, b, b->cord[0], b->cord[1]))
			return (paste_map(a, b, b->cord));
		else
		{
			(b->cord[1])++;
			if (b->cord[1] >= dim)
			{
				b->cord[1] = 0;
				(b->cord[0])++;
				if (b->cord[0] >= dim)
					return (0);
			}
		}
	}
	return (0);
}
