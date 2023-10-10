/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:27:34 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/10 16:18:54 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	change_pos(t_vars *vars, t_vector *new_pos)
{
	vars->_map->_pre_pos.x = vars->_map->_cur_pos.x;
	vars->_map->_pre_pos.y = vars->_map->_cur_pos.y;
	if (vars->_map->_data[new_pos->x][new_pos->y] != '1')
	{
		vars->_map->_cur_pos.x = new_pos->x;
		vars->_map->_cur_pos.y = new_pos->y;
	}
	printf("%d  %d\n", vars->_map->_pre_pos.x, vars->_map->_pre_pos.y);
	printf("%d  %d\n", vars->_map->_cur_pos.x, vars->_map->_cur_pos.y);
}

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	else if (keycode == 13)
		change_pos(vars, &(t_vector){vars->_map->_cur_pos.x - 1, vars->_map->_cur_pos.y});
	else if (keycode == 0)
		change_pos(vars, &(t_vector){vars->_map->_cur_pos.x, vars->_map->_cur_pos.y - 1});
	else if (keycode == 1)
		change_pos(vars, &(t_vector){vars->_map->_cur_pos.x + 1, vars->_map->_cur_pos.y});
	else if (keycode == 2)
		change_pos(vars, &(t_vector){vars->_map->_cur_pos.x, vars->_map->_cur_pos.y + 1});
	return (0);
}

int	close_win_mouse(void)
{
	exit(0);
}
