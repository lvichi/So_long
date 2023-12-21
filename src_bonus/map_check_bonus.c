/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:38:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/21 16:02:08 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_retangle(char **map)
{
	int	y;

	if (array_len(map) == str_len(map[0]))
		return (0);
	y = -1;
	while (map[++y])
		if (str_len(map[y]) != str_len(map[0]))
			return (0);
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
			else if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'K')
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

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (y == 0 || y == array_len(map) - 1)
				if (map[y][x] != '1')
					return (0);
			if (x == 0 || x == str_len(map[y]) - 1)
				if (map[y][x] != '1')
					return (0);
		}
	}
	return (1);
}

int	map_check(char **map)
{
	int	check;

	check = 0;
	if (!map)
		check = 1;
	else if (!check_retangle(map))
		check = 2;
	else if (!check_content(map))
		check = 3;
	else if (!check_wall(map))
		check = 4;
	else if (!check_path(map))
		check = 5;
	if (check != 0)
		free_map(map);
	return (check);
}
