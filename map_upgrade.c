/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_upgrade.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 08:48:17 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/24 12:13:36 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**table(int dim)
{
	char	**new;
	int		k;
	int		l;

	k = 0;
	if (!(new = (char **)malloc(sizeof(char *) * (dim + 1))))
		return (NULL);
	while (k < (dim + 1))
	{
		l = 0;
		if (!(new[k] = (char *)malloc(sizeof(char) * (dim + 1))))
			return (NULL);
		while (l < (dim + 1))
		{
			new[k][l] = '.';
			l++;
		}
		k++;
	}
	return (new);
}

char	**map_upgrade(t_map *map)
{
	char	**new;

	new = table(map->dim[0]);
	(map->dim[0])++;
	free(map->shape);
	return (new);
}
