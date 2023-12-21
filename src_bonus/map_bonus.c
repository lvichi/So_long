/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:58:14 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/21 18:56:41 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_image(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][0], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
	if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][1], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][2], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][3], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][4], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
	else if (game->map[y][x] == 'K')
		mlx_put_image_to_window(game->c_id, game->w_id,
			game->imgs[game->frame][5], x * IMG_WIDTH, y * IMG_HEIGHT + BANNER);
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
		while (++x < str_len(map[y]))
			draw_image(game, x, y);
	}
	draw_str(game);
}

char	**fill_map(char *buffer, char **map)
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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			write(1, &map[i][j], 1);
		write(1, "\n", 1);
	}
	write(1, "\n", 1);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}
