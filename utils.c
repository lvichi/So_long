/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/11 16:59:15 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (map[i] && map[i][j])
			write(1, &map[i][j++], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	map_size(char **map, int *map_x, int *map_y)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while(map[y][x] != '\n')
		x++;
	while (map[y])
		y++;
	*map_x = x * 50;
	*map_y = y * 50;
}
