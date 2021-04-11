/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_blank.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:15:10 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/23 22:44:56 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_pt(int i, int j, t_point *point)
{
	int	n;

	n = 0;
	while (n < 4)
	{
		if (i == point[n].x && j == point[n].y)
			return (1);
		n++;
	}
	return (0);
}

int	count_pt(int i, int j, t_point *point)
{
	int	x;
	int	y;
	int	n;

	x = 0;
	y = 0;
	n = 0;
	while (x <= i)
	{
		if (!(check_pt(x, y, point)))
			n++;
		if (++y > j)
		{
			x++;
			y = 0;
		}
	}
	return (n);
}

int	count_blank(t_point *point)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	j = 0;
	n = 0;
	while (n < 4)
	{
		if (i < point[n].x)
			i = point[n].x;
		if (j < point[n].y)
			j = point[n].y;
		n++;
	}
	return (count_pt(i, j, point));
}
