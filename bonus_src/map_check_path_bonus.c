/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/17 15:33:53 by lvichi           ###   ########.fr       */
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
			if (map[y][x] == 'P' || map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
	}
	return (1);
}

static void	flood_fill(char **map, int y, int x)
{
	map[y][x] = '-';
	if (map[y - 1][x] != '1' && map[y - 1][x] != '-')
		flood_fill(map, y - 1, x);
	if (map[y + 1][x] != '1' && map[y + 1][x] != '-')
		flood_fill(map, y + 1, x);
	if (map[y][x - 1] != '1' && map[y][x - 1] != '-')
		flood_fill(map, y, x - 1);
	if (map[y][x + 1] != '1' && map[y][x + 1] != '-')
		flood_fill(map, y, x + 1);
}

static void	start_pos(char **map, int *y, int *x)
{
	*y = -1;
	while (map[++(*y)])
	{
		*x = -1;
		while (map[*y][++(*x)])
			if (map[*y][*x] == 'P')
				return ;
	}
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
		new_map[y] = (char *)ft_calloc(sizeof(char), array_len(map[y]) + 1);
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

int	check_path(char **map)
{
	char	**test_map;
	int		y;
	int		x;

	test_map = duplicate_map(map);
	y = 0;
	x = 0;
	start_pos(test_map, &y, &x);
	flood_fill(test_map, y, x);
	if (!check_fill(test_map))
	{
		free_map(test_map);
		return (0);
	}
	free_map(test_map);
	return (1);
}
