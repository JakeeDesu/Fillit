/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iberchid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:17:59 by iberchid          #+#    #+#             */
/*   Updated: 2018/11/25 11:43:02 by iberchid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

typedef struct	s_tetris
{
	int			**shape;
	t_point		*points;
	int			*cord;
	int			x;
	int			n;
}				t_tetris;

typedef struct	s_map
{
	char	**shape;
	int		dim[1];
}				t_map;

int				blankcell(int **shape, int size, int dim);
char			**map_upgrade(t_map *map);
int				test_matching(t_map *a, t_tetris *b, int i, int j);
int				paste_map(t_map *a, t_tetris *b, int *cord);
int				check_all(t_map *a, t_tetris *b, int dim);
int				ft_sqrt(int n);
int				count_tetris(t_tetris **tetris);
void			clear_cord(char **map, t_tetris *tetris);
int				fill_map(t_map *land, t_tetris **tetris, int n, int m);
int				create_map(t_tetris **tetris, t_map *map);
void			print_map(char **map, int dim);
int				v_line(char *str);
void			to_points(t_tetris *tetris);
void			re_zero(t_tetris **tetris);
int				v_fillit(t_map *land, t_tetris **tetris);
int				test_valid(int fd);
int				line_valid(char *line, int *nb);
int				tetris_valid(t_point *points);
int				count_blank(t_point *point);
t_tetris		**holder(char *path);

#endif
