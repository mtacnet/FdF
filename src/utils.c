/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 11:06:30 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 10:48:38 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_pos(int i, int j, t_param **mlx, t_coord *pos)
{
	if (i < (*mlx)->nb_line - 1)
	{
		pos->x1 = ((j - i) * 50 + 550) * (*mlx)->zoom + (*mlx)->dep_x;
		pos->y1 = ((j + i) * 25 + 150 - (*mlx)->tab[i][j] * (*mlx)->alt) *
			(*mlx)->zoom + (*mlx)->dep_y;
		pos->x2 = ((j - (i + 1)) * 50 + 550) * (*mlx)->zoom + (*mlx)->dep_x;
		pos->y2 = ((j + (i + 1)) * 25 + 150 - (*mlx)->tab[i + 1][j] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->dep_y;
		draw(&pos, mlx);
	}
	if (j < (*mlx)->nb_col - 1)
	{
		pos->x1 = ((j - i) * 50 + 550) * (*mlx)->zoom + (*mlx)->dep_x;
		pos->y1 = ((j + i) * 25 + 150 - (*mlx)->tab[i][j] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->dep_y;
		pos->x2 = (((j + 1) - i) * 50 + 550) * (*mlx)->zoom + (*mlx)->dep_x;
		pos->y2 = (((j + 1) + i) * 25 + 150 - (*mlx)->tab[i][j + 1] *
				(*mlx)->alt) * (*mlx)->zoom + (*mlx)->dep_y;
		draw(&pos, mlx);
	}
}

void	init_mlx(t_param **mlx)
{
	if (!((*mlx)->id = mlx_init()))
	{
		ft_putendl("_INIT_ERROR_");
		exit(EXIT_FAILURE);
	}
	(*mlx)->win = mlx_new_window((*mlx)->id, (*mlx)->height, (*mlx)->width,
			"FdF");
}

void	view_usage(int value, t_param **mlx)
{
	if (value == 1)
	{
		ft_putendl("Usage: ./fdf [map_file]");
		exit(EXIT_FAILURE);
	}
	if (value == 2)
	{
		mlx_string_put((*mlx)->id, (*mlx)->win, 5, 5, 0x00FF00,
				"**************************************");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 25, 0x00FF00,
				"Zoom avant / arriere: + / -");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 45, 0x00FF00,
				"Deplacement: Touches A - W - S - D");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 65, 0x00FF00,
				"Augmenter altitude: Fleche-haut");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 85, 0x00FF00,
				"Diminuer altitude: Fleche-bas");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 105, 0x00FF00,
				"Changer couleur: Num. Pad de 1 a 9 ");
		mlx_string_put((*mlx)->id, (*mlx)->win, 15, 125, 0x00FF00,
				"Quitter: ESC");
		mlx_string_put((*mlx)->id, (*mlx)->win, 5, 145, 0x00FF00,
				"**************************************");
	}
}

void	view_int_tab(int **tab, int raw, int column)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < raw)
	{
		j = 0;
		while (j < column)
		{
			ft_putnbr(tab[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	verif_content(void *var)
{
	if (var == NULL)
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
}
