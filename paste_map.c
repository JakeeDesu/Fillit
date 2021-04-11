/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paste_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 12:39:14 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/18 00:17:33 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	paste_map(t_map *a, t_tetris *b, int *cord)
{
	a->shape[cord[0] + b->points[0].x][cord[1] + b->points[0].y] = 'A' + b->n;
	a->shape[cord[0] + b->points[1].x][cord[1] + b->points[1].y] = 'A' + b->n;
	a->shape[cord[0] + b->points[2].x][cord[1] + b->points[2].y] = 'A' + b->n;
	a->shape[cord[0] + b->points[3].x][cord[1] + b->points[3].y] = 'A' + b->n;
	return (1);
}
