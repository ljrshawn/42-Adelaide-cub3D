/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:19:19 by jlyu              #+#    #+#             */
/*   Updated: 2023/12/01 11:43:56 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	draw_map(t_vars *vars)
{
	int m = ((vars->width / 2) - 40) / vars->_map->_dm;
	int	n = (vars->height - 40) / vars->_map->_dn;
	int start_x;
	int start_y;
	if (vars->_map->_dn * m > vars->height)
	{
		start_x = ((vars->width / 2) - (vars->_map->_dm * n)) / 2;
		start_y = 20;
		m = n;
	}
	else
	{
		start_x = 20;
		start_y = ((vars->height - (vars->_map->_dn * m)) / 2);
	}

	for(int y = start_y; y < (vars->_map->_dn * m) + start_y; ++y)
	for(int x = start_x; x < (vars->_map->_dm * m) + start_x; ++x)
	{
		int y_co = (y - start_y) / m;
		int x_co = (x - start_x) / m;
		if (vars->_map->_data[y_co][x_co] == '1')
		{
			vars->color = 0xABCDEF;
			int pixel = (y * vars->line_bytes) + (x * 4);

			if (vars->endian == 1)
			{
				vars->buffer[pixel + 0] = (vars->color >> 24);
				vars->buffer[pixel + 1] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color) & 0xFF;
			}
			else if (vars->endian == 0)
			{
				vars->buffer[pixel + 0] = (vars->color) & 0xFF;
				vars->buffer[pixel + 1] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color >> 24);
			}
		}
		else if (y_co == vars->_map->_pre_pos.x && x_co == vars->_map->_pre_pos.y)
		{
			vars->color = 0x000000;
			int pixel = (y * vars->line_bytes) + (x * 4);

			if (vars->endian == 1)
			{
				vars->buffer[pixel + 0] = (vars->color >> 24);
				vars->buffer[pixel + 1] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color) & 0xFF;
			}
			else if (vars->endian == 0)
			{
				vars->buffer[pixel + 0] = (vars->color) & 0xFF;
				vars->buffer[pixel + 1] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color >> 24);
			}
		}
		else if (y_co == vars->_map->_cur_pos.x && x_co == vars->_map->_cur_pos.y)
		{
			vars->color = 0xFEDCBA;
			int pixel = (y * vars->line_bytes) + (x * 4);

			if (vars->endian == 1)
			{
				vars->buffer[pixel + 0] = (vars->color >> 24);
				vars->buffer[pixel + 1] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color) & 0xFF;
			}
			else if (vars->endian == 0)
			{
				vars->buffer[pixel + 0] = (vars->color) & 0xFF;
				vars->buffer[pixel + 1] = (vars->color >> 8) & 0xFF;
				vars->buffer[pixel + 2] = (vars->color >> 16) & 0xFF;
				vars->buffer[pixel + 3] = (vars->color >> 24);
			}
		}
	}
}

void	draw_game(t_vars *vars)
{
	t_vars	games;

	games.image = mlx_xpm_file_to_image(vars->mlx, TEXTURE_S, &(games.width), &(games.height));
	games.buffer = mlx_get_data_addr(games.image, &games.pixel_bits, &games.line_bytes, &games.endian);
	int count_h = -1;
		while (++count_h < games.height)
		{
			int count_w = -1;
			while (++count_w < games.width)
			{
				int vars_pixel = (count_w * vars->line_bytes) + (count_h * 4) + vars->line_bytes / 2;
				int games_pixel = (count_w * games.line_bytes) + (count_h * 4);
				if (vars->endian == 1)
				{
					vars->buffer[vars_pixel + 0] = (games.buffer[games_pixel + 0] >> 24);
					vars->buffer[vars_pixel + 1] = (games.buffer[games_pixel + 1] >> 16) & 0xFF;
					vars->buffer[vars_pixel + 2] = (games.buffer[games_pixel + 2] >> 8) & 0xFF;
					vars->buffer[vars_pixel + 3] = (games.buffer[games_pixel + 3]) & 0xFF;
				}
				else if (vars->endian == 0)
				{
					vars->buffer[vars_pixel + 0] = (games.buffer[games_pixel + 0]) & 0xFF;
					vars->buffer[vars_pixel + 1] = (games.buffer[games_pixel + 1] >> 8) & 0xFF;
					vars->buffer[vars_pixel + 2] = (games.buffer[games_pixel + 2] >> 16) & 0xFF;
					vars->buffer[vars_pixel + 3] = (games.buffer[games_pixel + 3] >> 24);
				}
			}
		}
}

void	cub3d_draw(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.width = 1920;
	vars.height = 1080;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "cub3D");
	vars.image = mlx_new_image(vars.mlx, vars.width, vars.height);
	vars.buffer = mlx_get_data_addr(vars.image, &vars.pixel_bits, &vars.line_bytes, &vars.endian);
	vars._map = map;
	draw_map(&vars);
	draw_game(&vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.image, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, key_press, &vars);
	mlx_hook(vars.win, 17, 1L << 5, close_win_mouse, &vars);
	mlx_loop(vars.mlx);
}