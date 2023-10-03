/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:10:57 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/03 17:09:58 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

char	*get_next_line(int fd)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	buffer = malloc(100000);
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	buffer[i] = '\0';
	if (rd == -1 || i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	if (buffer[i - 1] == '\n')
		buffer[i - 1] = '\0';
	return (buffer);
}

void	save_color(t_map *map, char *str, char flag)
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
}

void	append_map(t_map *map, char *string)
{
	int		m;
	int		i;
	int		j;
	char	**tem;

	m = ft_strlen(string);
	if (map->_dm < m)
		map->_dm = m;
	map->_dn++;
	tem = malloc((map->_dn + 1) * sizeof(char *));
	j = -1;
	while (++j < (map->_dn - 1))
		tem[j] = ft_strjoin("", map->_data[j]);
	tem[j] = malloc((map->_dm + 1) * sizeof(char));
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
	map->_data = tem;
}

void	save_to_map(t_map *map, char *string)
{
	if (ft_strncmp(string, "NO ", 3) == 0)
		map->_no = ft_strjoin("", ft_split(string, ' ')[1]);
	if (ft_strncmp(string, "SO ", 3) == 0)
		map->_so = ft_strjoin("", ft_split(string, ' ')[1]);
	if (ft_strncmp(string, "WE ", 3) == 0)
		map->_we = ft_strjoin("", ft_split(string, ' ')[1]);
	if (ft_strncmp(string, "EA ", 3) == 0)
		map->_ea = ft_strjoin("", ft_split(string, ' ')[1]);
	if (ft_strncmp(string, "F ", 2) == 0)
		save_color(map, ft_split(string, ' ')[1], 'F');
	if (ft_strncmp(string, "C ", 2) == 0)
		save_color(map, ft_split(string, ' ')[1], 'C');
	if (!*string)
		append_map(map, string);
}

void	read_file(t_map *map, char *path)
{
	int		fd;
	char	*string;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFailed to open the file %s\n", path);
		exit(1);
	}
	string = get_next_line(fd);
	while (string)
	{
		save_to_map(map, string);
		string = get_next_line(fd);
	}
	close(fd);
}
