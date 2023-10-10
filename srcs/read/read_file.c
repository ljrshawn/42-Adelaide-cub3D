/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:10:57 by jlyu              #+#    #+#             */
/*   Updated: 2023/10/10 15:53:29 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3D.h"

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
		free(string);
		string = get_next_line(fd);
	}
	close(fd);
}
