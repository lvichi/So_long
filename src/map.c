/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:58:14 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/14 17:59:57 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->c_id, game->w_id, game->imgs[0],
			x * IMG_WIDTH, y * IMG_HEIGHT);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->c_id, game->w_id, game->imgs[1],
			x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->c_id, game->w_id, game->imgs[2],
			x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->c_id, game->w_id, game->imgs[3],
			x * IMG_WIDTH, y * IMG_HEIGHT);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->c_id, game->w_id, game->imgs[4],
			x * IMG_WIDTH, y * IMG_HEIGHT);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	map = (char **)game->map;
	y = -1;
	while (++y < array_len(map))
	{
		x = -1;
		while (++x < array_len(map[y]))
			draw_image(game, x, y);
	}
}

static char	**fill_map(char *buffer, char **map)
{
	int		i;
	int		j;
	int		n;

	n = 0;
	i = -1;
	while (++i < MAX_Y && buffer[n] != 0)
	{
		map[i] = (char *)ft_calloc(sizeof(char), MAX_X + 1);
		if (!map[i])
		{
			free_map(map);
			return (NULL);
		}
		j = -1;
		while (buffer[n] != '\n' && buffer[n] != 0 && ++j < MAX_X)
			map[i][j] = buffer[n++];
		if (buffer[n] == '\n')
			n++;
	}
	free(buffer);
	return (map);
}

int	get_map(t_game *game, char *file)
{
	char	*buffer;
	int		error;
	char	**map;

	map = (char **)ft_calloc(sizeof(char *), MAX_Y + 1);
	if (!map)
		return (-1);
	buffer = read_file(file);
	if (!buffer)
		return (-1);
	game->map = fill_map(buffer, map);
	error = map_check(game->map);
	return (error);
}
