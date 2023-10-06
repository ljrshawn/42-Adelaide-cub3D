/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:07:53 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/06 16:21:57 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

static void	save_color(t_map *map, char *str, char flag)
{
	char	**rgb;

	rgb = ft_split(str, ',');
	if ((ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[0]) > 255)
		|| (ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[1]) > 255)
		|| (ft_atoi(rgb[2]) < 0 || ft_atoi(rgb[2]) > 255))
	{
		printf("Error\nIllegal color!\n");
		exit(1);
	}
	if (flag == 'F')
	{
		map->_fr = ft_atoi(rgb[0]);
		map->_fg = ft_atoi(rgb[1]);
		map->_fb = ft_atoi(rgb[2]);
	}
	else
	{
		map->_cr = ft_atoi(rgb[0]);
		map->_cg = ft_atoi(rgb[1]);
		map->_cb = ft_atoi(rgb[2]);
	}
	free_contain(rgb);
}

static void	copy_old(t_map *map, char **tem, char *string, int m)
{
	int		i;
	int		j;

	j = -1;
	if (map->_data != NULL)
	{
		while (++j < (map->_dn - 1))
		{
			tem[j] = ft_strjoin("", map->_data[j]);
			free(map->_data[j]);
		}
		free(map->_data);
		j--;
	}
	tem[++j] = malloc((map->_dm + 1) * sizeof(char));
	i = -1;
	while (++i < map->_dm)
	{
		if (string[i] == ' ' || i >= m)
			tem[j][i] = '-';
		else
			tem[j][i] = string[i];
	}
	tem[j][i] = '\0';
	tem[j + 1] = NULL;
}

static void	append_map(t_map *map, char *string)
{
	int		m;
	char	**tem;

	m = ft_strlen(string);
	if (m == 0)
		return ;
	if (map->_dm < m)
		map->_dm = m;
	map->_dn += 1;
	tem = malloc((map->_dn + 1) * sizeof(char *));
	copy_old(map, tem, string, m);
	map->_data = tem;
}

void	save_to_map(t_map *map, char *string)
{
	char	**tem;

	tem = ft_split(string, ' ');
	if (ft_strncmp(string, "NO ", 3) == 0)
		map->_no = ft_strjoin("", tem[1]);
	else if (ft_strncmp(string, "SO ", 3) == 0)
		map->_so = ft_strjoin("", tem[1]);
	else if (ft_strncmp(string, "WE ", 3) == 0)
		map->_we = ft_strjoin("", tem[1]);
	else if (ft_strncmp(string, "EA ", 3) == 0)
		map->_ea = ft_strjoin("", tem[1]);
	else if (ft_strncmp(string, "F ", 2) == 0)
		save_color(map, tem[1], 'F');
	else if (ft_strncmp(string, "C ", 2) == 0)
		save_color(map, tem[1], 'C');
	else
		append_map(map, string);
	free_contain(tem);
}
