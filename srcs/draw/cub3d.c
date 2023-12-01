/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:24:18 by jlyu              #+#    #+#             */
/*   Updated: 2023/11/20 13:41:16 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

void	cub3d(char **argv)
{
	t_map	map;
	(void) argv;

	init_map(&map);
	read_file(&map, *argv);
	// int i = -1;
	// while (++i < map._dn)
	// 	printf("%s\n", map._data[i]);
	cub3d_draw(&map);
	free_map(&map);
}
