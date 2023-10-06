/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:21:01 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/06 16:35:58 by jlyu             ###   ########.fr       */
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

typedef struct s_map
{
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	int		_fr;
	int		_fg;
	int		_fb;
	int		_cr;
	int		_cg;
	int		_cb;
	char	**_data;
	int		_dm;
	int		_dn;
}	t_map;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
}	t_vars;

// Main
void	cub3d(char **argv);

// Draw
void	cub3d_draw(t_map *map);

// Close
int		close_win_esc(int keycode, t_vars *vars);
int		close_win_mouse(void);

// Utils
void	init_map(t_map *map);
void	free_map(t_map *map);
void	free_contain(char **arr);

// Read file
void	read_file(t_map *map, char *path);
void	save_to_map(t_map *map, char *string);


#endif