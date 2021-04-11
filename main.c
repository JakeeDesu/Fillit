/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 10:01:04 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/25 11:40:27 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	main_anx(t_tetris ***tetris, char *path)
{
	int	i;
	int	nb;

	i = 0;
	*tetris = holder(path);
	nb = count_tetris(*tetris);
	while (i < nb)
	{
		if (!(tetris_valid(tetris[0][i]->points)))
		{
			ft_putstr("error\n");
			exit(0);
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	t_tetris	**pack;
	t_map		*map;
	int			x;
	int			fd;

	pack = NULL;
	x = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!(test_valid(fd)))
		{
			ft_putstr("error\n");
			exit(0);
		}
		main_anx(&pack, argv[1]);
		if (!(map = (t_map *)malloc(sizeof(t_map))))
			return (0);
		x = v_fillit(map, pack);
	}
	else
		ft_putstr("usage: fillit source_file\n");
	return (0);
}
