/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:17:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/13 22:17:53 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	test_map = duplicate_map(map);
	free_map(test_map);
	return (1);
}
