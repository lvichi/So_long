/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/15 00:19:10 by lvichi           ###   ########.fr       */
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
