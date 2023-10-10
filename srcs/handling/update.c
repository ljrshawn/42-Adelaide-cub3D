#include "../../inc/cub3D.h"

void	handle_2d_update(t_vars *vars)
{
	if (vars->_map->_pre_pos.x != vars->_map->_cur_pos.x || vars->_map->_pre_pos.y != vars->_map->_cur_pos.y)
		draw_map(vars);
}

int	updating(t_vars *vars)
{
	// if (vars->stopped == 1)
	// 	return (0);
	handle_2d_update(vars);
	return (0);
}