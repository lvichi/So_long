/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/20 20:49:37 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_fill(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'P' || map[y][x] == 'C')
				return (0);
	}
	return (1);
}

static void	flood_fill(char **map, int y, int x)
{
	if (y == -1 && x == -1)
	{
		while (map[++y])
		{
			x = -1;
			while (map[y][++x])
				if (map[y][x] == 'P')
					break ;
			if (map[y][x] && map[y][x] == 'P')
				break ;
		}
	}
	map[y][x] = '-';
	if (map[y - 1][x] != '1' && map[y - 1][x] != '-' && map[y - 1][x] != 'E')
		flood_fill(map, y - 1, x);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '-' && map[y + 1][x] != 'E')
		flood_fill(map, y + 1, x);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '-' && map[y][x - 1] != 'E')
		flood_fill(map, y, x - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '-' && map[y][x + 1] != 'E')
		flood_fill(map, y, x + 1);
}

static char	**duplicate_map(char **map)
{
	char	**new_map;
	int		y;
	int		x;

	new_map = (char **)ft_calloc(sizeof(char *), array_len(map) + 1);
	if (!new_map)
		return (NULL);
	y = -1;
	while (map[++y])
	{
		new_map[y] = (char *)ft_calloc(sizeof(char), str_len(map[y]) + 1);
		if (!new_map[y])
		{
			while (--y >= 0)
				free(new_map[y]);
			free(new_map);
			return (NULL);
		}
		x = -1;
		while (map[y] && map[y][++x])
			new_map[y][x] = map[y][x];
	}
	return (new_map);
}

static int	check_exit(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'E')
				break ;
		if (map[y][x] && map[y][x] == 'E')
			break ;
	}
	if (map[y + 1][x] == '-')
		return (1);
	if (map[y - 1][x] == '-')
		return (1);
	if (map[y][x + 1] == '-')
		return (1);
	if (map[y][x - 1] == '-')
		return (1);
	return (0);
}

int	check_path(char **map)
{
	char	**test_map;

	test_map = duplicate_map(map);
	flood_fill(test_map, -1, -1);
	if (!check_fill(test_map) || !check_exit(test_map))
	{
		free_map(test_map);
		return (0);
	}
	free_map(test_map);
	return (1);
}
