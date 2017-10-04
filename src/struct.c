/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 10:40:53 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/02 17:01:34 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_struct_mlx(t_param **mlx)
{
	(*mlx)->id = NULL;
	(*mlx)->win = NULL;
	(*mlx)->tab = NULL;
	(*mlx)->height = 1600;
	(*mlx)->width = 960;
	(*mlx)->alt = 5;
	(*mlx)->nb_line = 0;
	(*mlx)->nb_col = 0;
	(*mlx)->color = 0xFFFFFF;
	(*mlx)->dep_x = 200;
	(*mlx)->dep_y = 200;
	(*mlx)->zoom = 0.5;
}

void	init_struct_coord(t_coord *pos)
{
	pos->x1 = 0;
	pos->y1 = 0;
	pos->x2 = 0;
	pos->y2 = 0;
}
