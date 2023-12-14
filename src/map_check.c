/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:38:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/13 22:18:46 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_retangle(char **map)
{
	int	y;
	int	x;
	int	max_y;
	int	max_x;

	max_y = 0;
	while (map[max_y])
		max_y++;
	max_x = 0;
	while (map[0][max_x] != '\n' && map[0][max_x] != 0)
		max_x++;
	y = -1;
	while (map[++y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != 0)
			x++;
		if (max_y >= x || x != max_x)
			return (0);
	}
	return (1);
}

static int	check_content(char **map)
{
	int	y;
	int	x;
	int	content_p_c_e[3];

	content_p_c_e[0] = 0;
	content_p_c_e[2] = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				content_p_c_e[0] += 1;
			else if (map[y][x] == 'C')
				content_p_c_e[1] = 1;
			else if (map[y][x] == 'E')
				content_p_c_e[2] += 1;
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '\n')
				return (0);
		}
	}
	if (content_p_c_e[0] != 1 || content_p_c_e[1] != 1 || content_p_c_e[2] != 1)
		return (0);
	return (1);
}

static int	check_wall(char **map)
{
	int	y;
	int	x;
	int	max_y;
	int	max_x;

	max_y = 0;
	while (map[max_y])
		max_y++;
	max_x = 0;
	while (map[0][max_x] != '\n' && map[0][max_x] != 0)
		max_x++;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x] != '\n' && map[y][x] != 0)
		{
			if (y == 0 || x == 0 || y == (max_y -1) || x == (max_x - 1))
				if (map[y][x] != '1')
					return (0);
		}
	}
	return (1);
}

int	map_check(char **map)
{
	int	check;

	check = 1;
	if (!check_retangle(map))
		check = 0;
	else if (!check_content(map))
		check = 0;
	else if (!check_wall(map))
		check = 0;
	else if (!check_path(map))
		check = 0;
	if (check == 0)
		free_map(map);
	return (check);
}
