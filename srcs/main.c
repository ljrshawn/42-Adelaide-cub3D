/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlyu <jlyu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:24:24 by jlyu              #+#    #+#             */
/*   Updated: 2023/09/28 15:53:27 by jlyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		cub3d(++argv);
	else
	{
		printf("Error\ncorrect command %s <filename>\n", argv[0]);
		exit(0);
	}
	return (0);
}
