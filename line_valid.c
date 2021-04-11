/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmhindat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:13:20 by hmhindat          #+#    #+#             */
/*   Updated: 2018/11/24 12:11:26 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		line_valid(char *line, int *nb)
{
	int i;

	if (ft_strlen(line) != 4)
		return (0);
	i = 0;
	while (*line)
	{
		if (*line != '#' && *line != '.')
			return (0);
		if (*line == '#')
			i++;
		line++;
	}
	*nb += i;
	return (1);
}
