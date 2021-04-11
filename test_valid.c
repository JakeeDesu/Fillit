/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetris.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 02:52:44 by hmhindat          #+#    #+#             */
/*   Updated: 2018/11/24 12:14:42 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	test_valid(int fd)
{
	int		line_nb;
	char	*line;
	int		i;

	line_nb = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (!(line_valid(line, &i)))
			return (0);
		line_nb++;
		if (line_nb == 4)
		{
			if (i != 4)
				return (0);
			i = 0;
			line_nb = 0;
			if (!(get_next_line(fd, &line)))
				return (1);
			if (ft_strlen(line) > 0)
			{
				return (0);
			}
		}
	}
	return (0);
}
