/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:10:57 by jlyu              #+#    #+#             */
/*   Updated: 2023/09/28 16:35:54 by jlyu             ###   ########.fr       */
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
	return (buffer);
}

void	save_to_map(t_map *map, char *string)
{
	if (ft_strncmp(string, "NO ", 3) == 0)
		map->_no = ft_strjoin("", ft_split(string, ' ')[1]);
}

void	read_file(t_map *map, char *path)
{
	int		fd;
	char	*string;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nFailed to open the file %s\n", path);
		exit(0);
	}
	string = get_next_line(fd);
	while (string)
	{
		save_to_map(map, string);
		printf("%s", string);
		string = get_next_line(fd);
	}
	close(fd);
}
