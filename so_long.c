/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:33:46 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/08 17:10:09 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	g_end;

void	fill_map(char *buffer, char **map)
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
	map = (char **)ft_calloc(sizeof(char *), 10);
	if (!map)
	{
		free(buffer);
		return (NULL);
	}
	fill_map(buffer, map);
	free(buffer);
	return (map);
}

void	print_map(char **map)
{
	int	i;
	int j;

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

void	draw_image(void *c_id, void *w_id, void **imgs, char img, int p[2])
{
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

void	draw_map(void *conn_id, void *window_id, void **images, char **map)
{
	int	pos[2];

	pos[0] = -1;
	while (++pos[0] < 10)
	{
		pos[1] = -1;
		while (++pos[1] < 15)
		{
			draw_image(conn_id, window_id, images, map[pos[0]][pos[1]], pos);
		}
	}
}

void	game(char **map)
{
	void	*conn_id;
	void	*window_id;
	void	**images;
	int		i;

	conn_id = mlx_init();
	window_id = mlx_new_window(conn_id, 750, 500, "./so_long");
	if (!conn_id || !window_id)
		return ;
	images = get_images(conn_id);
	if (!images)
		return ;
	while (g_end)
	{
		draw_map(conn_id, window_id, images, map);
	}
	mlx_destroy_window(conn_id, window_id);
	i = -1;
	while (++i < 5)
		mlx_destroy_image(conn_id, images[i]);
	free(images);
	free(conn_id);
}

void	sig_handler(int	sig)
{
	if (sig == 2)
		g_end = 0;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (++i < 10)
		free(map[i]);
	free (map);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	signal(SIGINT, sig_handler);
	g_end = 1;
	map = get_map(argv[1]);
	if (!map)
	{
		write(1, "Invalid map\n", 12);
		return(0);
	}
	print_map(map);
	game(map);
	free_map(map);
}

/*void	*new_window(void *conn_id)
{
	void	*window_id;
mlx_put_image_to_window(conn_id, window_id, water_id, 300, 300);
	window_id = mlx_new_window(conn_id, 750, 500, "./so_long");
	return (window_id);
}

int	main(void)
{
	void	*conn_id;
	void	*window_id;
	void	*water_id;
	int		i;
	int		j;
	int		width;
	int		height;
	
	width = 50;
	height = 50;
	conn_id = mlx_init();
	window_id = new_window(conn_id);
	sleep(5);mlx_put_image_to_window(conn_id, window_id, water_id, 300, 300);
	i = 50;
	while (i++ < 100)
	{
		j = 50;
		while (j++ < 100)
			mlx_pixel_put(conn_id, window_id, i, j, 0xffa500);
	}
	mlx_string_put(conn_id, window_id, 180, 180, 0xffa500, "TEST");
	sleep(5);
	water_id = mlx_xpm_file_to_image(conn_id, "images/collect.xpm", &width, &height);
	mlx_put_image_to_window(conn_id, window_id, water_id, 300, 300);
	sleep(5);
	mlx_destroy_window(conn_id, window_id);
	sleep(2);
	write(1, "Done!\n", 6);
}*/