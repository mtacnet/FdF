/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 11:39:27 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 11:31:13 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		verif(t_coord **pos)
{
	int		tmp;

	if ((*pos)->x1 > (*pos)->x2)
	{
		tmp = (*pos)->x1;
		(*pos)->x1 = (*pos)->x2;
		(*pos)->x2 = tmp;
		tmp = (*pos)->y1;
		(*pos)->y1 = (*pos)->y2;
		(*pos)->y2 = tmp;
	}
}

static void		draw2(t_coord **pos, t_param **mlx, int dx, int dy)
{
	int		e;
	int		i;

	i = (dx >= -dy);
	e = i ? dx : dy;
	dx = i ? e * 2 : dx * 2;
	dy = i ? dy * 2 : e * 2;
	while (i ? (*pos)->x1 < (*pos)->x2 : (*pos)->y1 > (*pos)->y2)
	{
		mlx_pixel_put((*mlx)->id, (*mlx)->win, (*pos)->x1, (*pos)->y1,
				(*mlx)->color);
		e = i ? e + dy : e + dx;
		if (i ? e < 0 : e > 0)
		{
			i ? (*pos)->y1-- : (*pos)->x1++;
			e = i ? e + dx : e + dy;
		}
		i ? (*pos)->x1++ : (*pos)->y1--;
	}
}

static void		assign_values(int e, int dx, int dy)
{
	e = (dx >= dy) ? dx : dy;
	dx = (dx >= dy) ? e * 2 : dx * 2;
	dy = (dx >= dy) ? dy * 2 : e * 2;
}

void			draw(t_coord **pos, t_param **mlx)
{
	int		dx;
	int		dy;
	int		e;

	verif(pos);
	e = 0;
	dy = (*pos)->y2 - (*pos)->y1;
	dx = (*pos)->x2 - (*pos)->x1;
	if (dy >= 0)
	{
		while ((*pos)->x1 < (*pos)->x2)
		{
			assign_values(e, dx, dy);
			f_norme(mlx, (*pos)->x1, (*pos)->y1);
			if ((e = (dx >= dy) ? e - dy : e - dx) < 0)
			{
				(dx >= dy) ? (*pos)->y1++ : (*pos)->x1++;
				e = (dx >= dy) ? e + dx : e + dy;
			}
			(dx >= dy) ? (*pos)->x1++ : (*pos)->y1++;
		}
	}
	else
		draw2(pos, mlx, dx, dy);
	f_norme(mlx, (*pos)->x2, (*pos)->y2);
}

void			core(t_param **mlx)
{
	t_coord		pos;
	int			i;
	int			j;

	i = 0;
	j = 0;
	init_struct_coord(&pos);
	while (i < (*mlx)->nb_line)
	{
		j = 0;
		while (j < (*mlx)->nb_col)
		{
			set_pos(i, j, mlx, &pos);
			j++;
		}
		i++;
	}
	view_usage(2, mlx);
	mlx_hook((*mlx)->win, 2, 3, manage_key, mlx);
	mlx_loop((*mlx)->id);
}
