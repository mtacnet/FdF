/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 10:46:17 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 11:40:04 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		verif_line(char *line, int i, t_param **mlx)
{
	int		j;

	j = 0;
	if (i == 0)
		(*mlx)->nb_col = ft_countword(line, ' ');
	if (i != 0)
	{
		j = ft_countword(line, ' ');
		if (j != (*mlx)->nb_col)
		{
			ft_putendl("Found wrong line length. Exiting.");
			return (1);
		}
	}
	return (0);
}

void			verif_fd(int fd)
{
	if (fd < 0)
	{
		ft_putendl("opening_error");
		exit(EXIT_FAILURE);
	}
}

int				check_map(char *map, t_param **mlx)
{
	int		fd;
	int		ret;
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	fd = open(map, O_RDONLY);
	verif_fd(fd);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (verif_line(line, i, mlx) != 0)
		{
			close(fd);
			ft_strdel(&line);
			return (1);
		}
		i++;
		ft_strdel(&line);
	}
	(*mlx)->nb_line = i;
	close(fd);
	return (0);
}
