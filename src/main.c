/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 14:34:20 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 10:46:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		verif_arg(char *argv)
{
	int		i;

	i = ft_strlenint(argv) - 4;
	if (ft_strcmp(&argv[i], ".fdf") == 0)
		return (1);
	else
		return (0);
}

int				main(int argc, char **argv)
{
	t_param		*mlx;
	char		*map;

	map = NULL;
	mlx = (t_param*)malloc(sizeof(t_param));
	init_struct_mlx(&mlx);
	if (argc != 2)
		view_usage(1, &mlx);
	else
	{
		if (verif_arg(argv[1]) != 0)
		{
			if (check_map(argv[1], &mlx) != 0)
				exit(EXIT_FAILURE);
			else
				map = map_to_string(argv[1], &mlx);
			map_to_tab(&mlx, map);
			ft_strdel(&map);
			init_mlx(&mlx);
			core(&mlx);
		}
		else
			ft_putendl("No data found.");
	}
	return (0);
}
