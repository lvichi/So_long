/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:38:22 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/11 21:58:54 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_retangle(char **map)
{
	int	y;
	int	x;
	int max_y;
	int max_x;

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
		ft_putnbr_fd(x, 1);
		write(1, "\n", 1);
		if (max_y >= x || x != max_x)
			return (0);
	}
	return (1);
}

/*static int check_content(char **map)
{
	int y;
	int x;
	int player;
	int	collective;
	int exit;

	player = 0;
	collective = 0;
	exit = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				player += 1;
			if (map[y][x] == 'E')
				exit += 1;
			if (map[y][x] == 'C')
				collective += 1;
		}
	}
	if (player != 1 || exit != 1 || collective == 0)
		return (0);
	return (1);
}*/

static void	free_map(char **map)
{
	int i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

int	map_check(char **map)
{
	int check;

	check = 1;
	if (!check_retangle(map))
		check = 0;
	//else if (!check_content(map))
	//	check = 0;
	if (check == 0)
		free_map(map);
	return (check);
}