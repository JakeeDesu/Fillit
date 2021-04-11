/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:20:04 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/17 22:05:39 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	create_map(t_tetris **tetris, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->dim[0] = ft_sqrt(count_tetris(tetris) * 4);
	if (!(map->shape = (char **)malloc(sizeof(char *) * (map->dim[0]))))
		return (0);
	while (i < map->dim[0])
	{
		j = 0;
		if (!(map->shape[i] = (char *)malloc(sizeof(char) * (map->dim[0]))))
			return (0);
		while (j < map->dim[0])
		{
			map->shape[i][j] = '.';
			j++;
		}
		i++;
	}
	return (1);
}
