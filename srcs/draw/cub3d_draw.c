/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:19:19 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/06 16:37:37 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

// void	cub3d_draw(t_map *map)
// {
// 	t_vars	vars;
// 	// int		ratio;

// 	// ratio = data[0][1] / data[0][0];
// 	// if (data[0][1] % data[0][0] != 0)
// 	// 	ratio += 1;
// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 720, 720, "cub3D");
// 	// draw_img(&vars, data, ratio);
// 	void *image = mlx_new_image(vars.mlx, 720, 720);
// 	int color = 0xABCDEF;

// 	int pixel_bits;
// 	int line_bytes;
// 	int endian;
// 	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

// 	if (pixel_bits != 32)
// 		color = mlx_get_color_value(vars.mlx, color);

// 	for(int y = 0; y < 360; ++y)
// 	for(int x = 0; x < 720; ++x)
// 	{
// 		int pixel = (y * line_bytes) + (x * 4);

// 		if (endian == 1)
// 		{
// 			buffer[pixel + 0] = (color >> 24);
// 			buffer[pixel + 1] = (color >> 16) & 0xFF;
// 			buffer[pixel + 2] = (color >> 8) & 0xFF;
// 			buffer[pixel + 3] = (color) & 0xFF;
// 		}
// 		else if (endian == 0)
// 		{
// 			buffer[pixel + 0] = (color) & 0xFF;
// 			buffer[pixel + 1] = (color >> 8) & 0xFF;
// 			buffer[pixel + 2] = (color >> 16) & 0xFF;
// 			buffer[pixel + 3] = (color >> 24);
// 		}
// 		// buffer[(y * line_bytes) + (x * 4)] = color;
// 	}
// 	mlx_put_image_to_window(vars.mlx, vars.win, image, 0, 0);

// 	// int		img_width = 20;
// 	// 	int		img_height = 20;
// 	// char	*relative_path = "../texture/wall.jpeg";
// 	// void	*image = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
// 	// mlx_put_image_to_window(vars.mlx, vars.win, image, 0, 0);

// 	mlx_hook(vars.win, 2, 1L << 0, close_win_esc, &vars);
// 	mlx_hook(vars.win, 17, 1L << 5, close_win_mouse, &vars);
// 	mlx_loop(vars.mlx);
// }

void	draw_map(t_map *map, t_vars *vars)
{
	void *image = mlx_new_image(vars->mlx, vars->width / 2, vars->height);
	int color = 0xABCDEF;

	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(image, &pixel_bits, &line_bytes, &endian);

	if (pixel_bits != 32)
		color = mlx_get_color_value(vars->mlx, color);

	for(int y = 0; y < vars->height; ++y)
	for(int x = 0; x < vars->width / 2; ++x)
	{
		int pixel = (y * line_bytes) + (x * 4);

		if (endian == 1)
		{
			buffer[pixel + 0] = (color >> 24);
			buffer[pixel + 1] = (color >> 16) & 0xFF;
			buffer[pixel + 2] = (color >> 8) & 0xFF;
			buffer[pixel + 3] = (color) & 0xFF;
		}
		else if (endian == 0)
		{
			buffer[pixel + 0] = (color) & 0xFF;
			buffer[pixel + 1] = (color >> 8) & 0xFF;
			buffer[pixel + 2] = (color >> 16) & 0xFF;
			buffer[pixel + 3] = (color >> 24);
		}
		// buffer[(y * line_bytes) + (x * 4)] = color;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, image, 0, 0);
}

void	cub3d_draw(t_map *map)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.width = 1440;
	vars.height = 720;
	vars.win = mlx_new_window(vars.mlx, vars.width, vars.height, "cub3D");
	draw_map(map, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_win_esc, &vars);
	mlx_hook(vars.win, 17, 1L << 5, close_win_mouse, &vars);
	mlx_loop(vars.mlx);
}