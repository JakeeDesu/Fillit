/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:07:07 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/19 22:46:37 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	fill_map(t_map *land, t_tetris **tetris, int n, int m)
{
	if (n >= count_tetris(tetris))
		return (n);
	if (!(check_all(land, tetris[n], land->dim[0])))
	{
		if (n == 0)
		{
			if (!(land->shape = map_upgrade(land)))
				return (0);
			re_zero(tetris);
			return (0);
		}
		else
			clear_cord(land->shape, tetris[--n]);
	}
	else
		n++;
	m++;
	if (m > 1000)
		return (n);
	return (fill_map(land, tetris, n, m));
}

int	v_fillit(t_map *land, t_tetris **tetris)
{
	int	x;

	x = 0;
	if (count_tetris(tetris) == 0)
		return (0);
	if (land->shape == NULL && create_map(tetris, land) == 0)
		return (0);
	while (x < count_tetris(tetris))
		x = fill_map(land, tetris, x, 0);
	print_map(land->shape, land->dim[0]);
	return (1);
}
