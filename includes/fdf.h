/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 13:32:22 by mtacnet           #+#    #+#             */
/*   Updated: 2017/10/04 11:38:12 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct		s_coord
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
}					t_coord;

typedef struct		s_param
{
	void			*id;
	void			*win;
	int				**tab;
	int				height;
	int				width;
	int				alt;
	int				nb_line;
	int				nb_col;
	int				color;
	int				dep_x;
	int				dep_y;
	float			zoom;
	t_coord			coord;
}					t_param;

/*
** MAIN FUNCTIONS
*/

void				draw(t_coord **pos, t_param **mlx);
void				set_pos(int i, int j, t_param **mlx, t_coord *pos);
void				view_usage(int value, t_param **mlx);
void				init_struct_mlx(t_param **mlx);
void				init_struct_coord(t_coord *pos);
void				map_to_tab(t_param **mlx, char *map);
void				view_int_tab(int **tab, int raw, int column);
void				verif_content(void *var);
void				init_mlx(t_param **mlx);
void				core(t_param **mlx);
void				init_mlx(t_param **mlx);
void				f_norme(t_param **mlx, int x, int y);
void				verif_fd(int fd);
char				*map_to_string(char *map, t_param **mlx);
int					check_map(char *argv, t_param **mlx);
int					manage_key(int keycode, t_param **mlx);

#endif
