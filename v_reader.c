/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_reader.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 08:39:52 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/25 09:49:25 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			**compress(int **new)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = blankcell(new, 4, 1);
	j = blankcell(new, 4, 0);
	x = 0;
	y = 0;
	while (x < 4)
	{
		if ((x + i) < 4 && (y + j) < 4)
			new[x][y] = new[x + i][y + j];
		else
			new[x][y] = 0;
		if (++y == 4)
		{
			x++;
			y = 0;
		}
	}
	return (new);
}

int			readline(int fd, int *line, int x)
{
	char	*str;
	int		n;

	n = 0;
	if (!(get_next_line(fd, &str)))
		return (2);
	if (v_line(str) == 2 && x == 0)
	{
		if (!(get_next_line(fd, &str)))
			return (2);
	}
	if (v_line(str) != 1)
		return (0);
	while (n < 4)
	{
		if (str[n] == '#')
			line[n] = 1;
		else
			line[n] = 0;
		n++;
	}
	return (1);
}

int			new_tetris(t_tetris **tetris, int fd, int i, int x)
{
	int			**shape;
	int			n;

	n = 0;
	if (!(tetris[0] = (t_tetris *)malloc(sizeof(t_tetris))))
		return (0);
	if (!(shape = (int **)malloc(sizeof(int *) * 4)))
		return (0);
	while (n < 4 && i == 1 && fd > 0)
	{
		shape[n] = (int *)malloc(sizeof(int) * 4);
		if (readline(fd, shape[n], n) != 1)
			return (0);
		n++;
	}
	tetris[0]->shape = compress(shape);
	to_points(tetris[0]);
	tetris[0]->cord = (int *)malloc(sizeof(int) * 2);
	tetris[0]->cord[0] = 0;
	tetris[0]->cord[1] = 0;
	tetris[0]->x = 0;
	tetris[0]->n = x;
	return (1);
}

t_tetris	**add_tetris(t_tetris **pack, int n)
{
	t_tetris	**new;
	int			i;

	if (n > 26)
	{
		ft_putstr("error\n");
		exit(0);
	}
	i = 0;
	if (!(new = (t_tetris **)malloc(sizeof(t_tetris *) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		new[i] = pack[i];
		i++;
	}
	return (new);
}

t_tetris	**holder(char *path)
{
	t_tetris	**pack;
	int			fd;
	int			n;

	n = 0;
	fd = open(path, O_RDONLY);
	while (fd)
	{
		pack = add_tetris(pack, n);
		if (new_tetris(&(pack[n]), fd, 1, n) != 1)
		{
			if (n == 0)
			{
				ft_putstr("error\n");
				exit(0);
			}
			else
			{
				pack[n] = 0;
				return (pack);
			}
		}
		n++;
	}
	return (NULL);
}
