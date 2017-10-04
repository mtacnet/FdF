/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:02:12 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 11:39:06 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			f_norme(t_param **mlx, int x, int y)
{
	mlx_pixel_put((*mlx)->id, (*mlx)->win, x, y, (*mlx)->color);
}

static void		alloc_tab(t_param **mlx)
{
	int		i;

	i = 0;
	(*mlx)->tab = (int**)ft_memalloc(sizeof(int*) * (*mlx)->nb_line);
	while (i < (*mlx)->nb_line)
	{
		(*mlx)->tab[i] = (int*)ft_memalloc(sizeof(int) * (*mlx)->nb_col);
		i++;
	}
}

void			map_to_tab(t_param **mlx, char *map)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	alloc_tab(mlx);
	verif_content((*mlx)->tab);
	i = 0;
	while (x < (*mlx)->nb_line)
	{
		y = 0;
		while (y < (*mlx)->nb_col)
		{
			while (map[i] && ft_isspace(map[i]) == 1)
				i++;
			(*mlx)->tab[x][y] = ft_atoi(&map[i]);
			while (map[i] && ft_isspace(map[i]) == 0)
				i++;
			y++;
		}
		x++;
	}
}

char			*map_to_string(char *argv, t_param **mlx)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;
	char	*map;

	line = NULL;
	tmp = NULL;
	map = NULL;
	if (!(map = ft_memalloc(sizeof((*mlx)->nb_col * (*mlx)->nb_line) + 1)))
		exit(EXIT_FAILURE);
	fd = open(argv, O_RDONLY);
	verif_fd(fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strdup(line);
		map = ft_strjoinfree(map, tmp, 1);
		map = ft_strjoinfree(map, " ", 1);
		ft_strdel(&line);
		ft_strdel(&tmp);
	}
	if (tmp)
		ft_strdel(&tmp);
	close(fd);
	return (map);
}
