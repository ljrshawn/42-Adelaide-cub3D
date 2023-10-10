/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:58:41 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/10 15:54:06 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	init_map(t_map *map)
{
	map->_data = NULL;
	map->_dm = 0;
	map->_dn = 0;
}

void	free_map(t_map *map)
{
	free(map->_no);
	free(map->_so);
	free(map->_we);
	free(map->_ea);
	free_contain(map->_data);
}

void	free_contain(char **arr)
{
	char	**tem;

	tem = arr;
	while (*tem)
	{
		free(*tem);
		tem++;
	}
	free(arr);
}
