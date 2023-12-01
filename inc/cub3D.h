/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:21:01 by jlyu              #+#    #+#             */
/*   Updated: 2023/11/30 15:13:12 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdio.h>

# include "../libs/libft/libft.h"
# include "../libs/mlx/mlx.h"

# define TEXTURE_S "/Users/jlyu/Documents/Cursus/MyGit/cub3D/texture/wall_s.xpm"
typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_map
{
	char		*_no;
	char		*_so;
	char		*_we;
	char		*_ea;
	int			_fr;
	int			_fg;
	int			_fb;
	int			_cr;
	int			_cg;
	int			_cb;
	char		**_data;
	int			_dm;
	int			_dn;
	t_vector	_cur_pos;
	t_vector	_pre_pos;
}	t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		*image;
	int			width;
	int			height;
	int			color;
	int			pixel_bits;
	int			line_bytes;
	int			endian;
	char		*buffer;
	t_map		*_map;
}	t_vars;

// Main
void	cub3d(char **argv);

// Draw
void	cub3d_draw(t_map *map);
void	draw_map(t_vars *vars);
void	draw_game(t_vars *vars);

// handling
int		key_press(int keycode, t_vars *vars);
int		close_win_mouse(void);
int		updating(t_vars *vars);

// Utils
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_contain(char **arr);

// Read file
void	read_file(t_map *map, char *path);
void	save_to_map(t_map *map, char *string);

#endif