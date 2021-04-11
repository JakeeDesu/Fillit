/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blankcell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:50:56 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/25 11:41:01 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	blankcell(int **shape, int size, int dim)
{
	int	i;
	int	j;
	int	*n;

	i = 0;
	j = 0;
	if (dim == 0)
		n = &i;
	if (dim == 1)
		n = &j;
	while (i < size && j < size)
	{
		if (shape[i][j] == 1 && dim == 0)
			return (j);
		if (shape[i][j] == 1 && dim == 1)
			return (i);
		(*n)++;
		if (dim == 0 && i == 4)
			j++;
		if (dim == 1 && j == 4)
			i++;
		if (*n == 4)
			*n = 0;
	}
	return (-1);
}
