/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 15:24:18 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/03 17:02:42 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	cub3d(char **argv)
{
	t_map	map;

	read_file(&map, *argv);
	int i = -1;
	while (++i < map._dn)
		printf("%s\n", map._data[i]);
}
