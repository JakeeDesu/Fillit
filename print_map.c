/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 20:44:50 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/17 21:50:32 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(char **map, int dim)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (map)
	{
		while (x < dim)
		{
			ft_putchar(map[x][y]);
			y++;
			if (y >= dim)
			{
				ft_putchar('\n');
				y = 0;
				x++;
			}
		}
	}
}
