/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/14 16:54:29 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*read_file(char *file)
{
	ssize_t	fd;
	ssize_t	read_return;
	char	*buffer;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buffer = (char *)ft_calloc(sizeof(char), MAX_FILE_SIZE);
	if (!buffer)
		return (NULL);
	read_return = read(fd, buffer, MAX_FILE_SIZE);
	if (read_return == -1)
		return (NULL);
	return (buffer);
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	free_images(t_game *game)
{
	int	i;

	i = -1;
	while (++i < MAX_IMG)
		if (game->imgs[i])
			mlx_destroy_image(game->c_id, game->imgs[i]);
	free(game->imgs);
}

int	array_len(void *array)
{
	int	array_check;
	int	i;

	i = 0;
	array_check = *((char *)array) >> 8;
	if (array_check)
	{
		while (*((char **)array))
		{
			array = (char **)array + 1;
			i++;
		}
	}
	else
	{
		while (*((char *)array))
		{
			array = (char *)array + 1;
			i++;
		}
	}
	return (i);
}
