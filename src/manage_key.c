/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:37:50 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/02 17:49:58 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Zoom +: 69 / 24 (touche +)
** Zoom -: 78 / 27(touche -)
** Echap (quit): 53 (touche ESC)
** Altitude +: 126 (fleche haut)
** Altitude -: 125 (fleche bas)
*/

static void		rear_zoom(t_param **mlx)
{
	(*mlx)->zoom -= 0.02;
	if ((*mlx)->zoom < 0.01)
		(*mlx)->zoom = 0.01;
}

static void		change_color(int keycode, t_param **mlx)
{
	if (keycode == 83)
		(*mlx)->color = 0xFFFFFF;
	if (keycode == 84)
		(*mlx)->color = 0xFF0000;
	if (keycode == 85)
		(*mlx)->color = 0x00FF00;
	if (keycode == 86)
		(*mlx)->color = 0x0000FF;
	if (keycode == 87)
		(*mlx)->color = 0xFF00FF;
	if (keycode == 88)
		(*mlx)->color = 0xFFFF00;
	if (keycode == 89)
		(*mlx)->color = 0xFD6C9E;
	if (keycode == 91)
		(*mlx)->color = 0x26C4EC;
	if (keycode == 92)
		(*mlx)->color = 0xAE642D;
}

static void		move(int keycode, t_param **mlx)
{
	if (keycode == 2)
		(*mlx)->dep_x += 10;
	if (keycode == 0)
		(*mlx)->dep_x -= 10;
	if (keycode == 1)
		(*mlx)->dep_y += 10;
	if (keycode == 13)
		(*mlx)->dep_y -= 10;
}

int				manage_key(int keycode, t_param **mlx)
{
	if (keycode == 69 || keycode == 24)
		(*mlx)->zoom += 0.02;
	if (keycode == 78 || keycode == 27)
		rear_zoom(mlx);
	if (keycode == 53)
	{
		mlx_destroy_window((*mlx)->id, (*mlx)->win);
		ft_memdel((void**)mlx);
		ft_putendl("QUIT");
		exit(EXIT_SUCCESS);
	}
	if (keycode == 126)
		(*mlx)->alt += 5;
	if (keycode == 125)
		(*mlx)->alt -= 5;
	if (keycode >= 83 && keycode <= 92)
		change_color(keycode, mlx);
	if (keycode >= 0 && keycode <= 13)
		move(keycode, mlx);
	mlx_clear_window((*mlx)->id, (*mlx)->win);
	core(mlx);
	return (0);
}
