/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/11 20:36:52 by lvichi           ###   ########.fr       */
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
		j = 0;
		while (map[i] && map[i][j])
			write(1, &map[i][j++], 1);
	}
	write(1, "\n", 1);
}

void	map_size(char **map, int *map_x, int *map_y)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y][x] != '\n')
		x++;
	while (map[y])
		y++;
	*map_x = x * 50;
	*map_y = y * 50;
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
