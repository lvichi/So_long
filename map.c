/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 21:58:14 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/11 17:03:40 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_image(t_game *game, char img, int p[2])
{
	void	*c_id;
	void	*w_id;
	void	**imgs;

	c_id = game->conn_id;
	w_id = game->window_id;
	imgs = (void **)game->images;
	if (img == '1')
		mlx_put_image_to_window(c_id, w_id, imgs[0], (p[1] * 50), (p[0] * 50));
	else if (img == '0')
		mlx_put_image_to_window(c_id, w_id, imgs[1], (p[1] * 50), (p[0] * 50));
	else if (img == 'P')
		mlx_put_image_to_window(c_id, w_id, imgs[2], (p[1] * 50), (p[0] * 50));
	else if (img == 'C')
		mlx_put_image_to_window(c_id, w_id, imgs[3], (p[1] * 50), (p[0] * 50));
	else if (img == 'E')
		mlx_put_image_to_window(c_id, w_id, imgs[4], (p[1] * 50), (p[0] * 50));
}

void	*get_images(void *conn_id)
{
	void	**images;
	int		i;
	int		w;

	w = 50;
	images = (void **)malloc(sizeof(void *) * 5);
	images[0] = mlx_xpm_file_to_image(conn_id, "images/wall.xpm", &w, &w);
	images[1] = mlx_xpm_file_to_image(conn_id, "images/background.xpm", &w, &w);
	images[2] = mlx_xpm_file_to_image(conn_id, "images/player.xpm", &w, &w);
	images[3] = mlx_xpm_file_to_image(conn_id, "images/collect.xpm", &w, &w);
	images[4] = mlx_xpm_file_to_image(conn_id, "images/exit.xpm", &w, &w);
	i = -1;
	while (++i < 5)
	{
		if (!images[i])
		{
			free(images);
			return (NULL);
		}
	}
	return (images);
}

void	draw_map(t_game *game)
{
	int		pos[2];
	char	**map;

	map = (char **)game->map;
	pos[0] = -1;
	while (++pos[0] < 10)
	{
		pos[1] = -1;
		while (++pos[1] < 15)
		{
			draw_image(game, map[pos[0]][pos[1]], pos);
		}
	}
}

static void	fill_map(char *buffer, char **map)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	n = 0;
	while (i < 10)
	{
		j = 0;
		map[i] = (char *)ft_calloc(sizeof(char), 17);
		while (buffer[n] != '\n' && buffer[n] != 0 && j < 15)
			map[i][j++] = buffer[n++];
		map[i][j] = buffer[n++];
		i++;
	}
	map[i] = 0;
}

char	**get_map(char *file)
{
	ssize_t	fd;
	char	**map;
	size_t	buffer_size;
	char	*buffer;
	ssize_t	read_return;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer_size = 160;
	buffer = (char *)ft_calloc(sizeof(char), 160);
	read_return = read(fd, buffer, buffer_size);
	if (read_return == -1)
		return (NULL);
	map = (char **)ft_calloc(sizeof(char *), 11);
	if (!map)
	{
		free(buffer);
		return (NULL);
	}
	fill_map(buffer, map);
	free(buffer);
	return (map);
}
