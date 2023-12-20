/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:49:21 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/20 18:47:05 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	frame_loop(t_game *game)
{
	static int	last_frame;
	static int	time;

	if (!(time % 2500))
	{
		if (game->frame == 0)
			game->frame++;
		else if (game->frame == 1 && last_frame == 0)
			game->frame++;
		else if (game->frame == 1 && last_frame == 2)
			game->frame--;
		else if (game->frame == 2)
			game->frame--;
		if (game->frame != 1)
			last_frame = game->frame;
		draw_map(game);
	}
	time++;
	return (0);
}

static int	get_frame_0(t_game *game)
{
	int		i;
	int		w;
	int		h;

	w = IMG_WIDTH;
	h = IMG_HEIGHT;
	game->imgs[0] = (void **)ft_calloc(sizeof(void *), MAX_IMG + 1);
	if (!game->imgs[0])
		return (0);
	game->imgs[0][0] = mlx_xpm_file_to_image(game->c_id, WALL_0, &w, &h);
	game->imgs[0][1] = mlx_xpm_file_to_image(game->c_id, BACK_0, &w, &h);
	game->imgs[0][2] = mlx_xpm_file_to_image(game->c_id, PLAYER_0, &w, &h);
	game->imgs[0][3] = mlx_xpm_file_to_image(game->c_id, COLLECT_0, &w, &h);
	game->imgs[0][4] = mlx_xpm_file_to_image(game->c_id, EXIT_0, &w, &h);
	i = -1;
	while (++i < MAX_IMG)
	{
		if (!game->imgs[0][i])
		{
			free_images(game);
			return (0);
		}
	}
	return (1);
}

static int	get_frame_1(t_game *game)
{
	int		i;
	int		w;
	int		h;

	w = IMG_WIDTH;
	h = IMG_HEIGHT;
	game->imgs[1] = (void **)ft_calloc(sizeof(void *), MAX_IMG + 1);
	if (!game->imgs[1])
		return (0);
	game->imgs[1][0] = mlx_xpm_file_to_image(game->c_id, WALL_1, &w, &h);
	game->imgs[1][1] = mlx_xpm_file_to_image(game->c_id, BACK_1, &w, &h);
	game->imgs[1][2] = mlx_xpm_file_to_image(game->c_id, PLAYER_1, &w, &h);
	game->imgs[1][3] = mlx_xpm_file_to_image(game->c_id, COLLECT_1, &w, &h);
	game->imgs[1][4] = mlx_xpm_file_to_image(game->c_id, EXIT_1, &w, &h);
	i = -1;
	while (++i < MAX_IMG)
	{
		if (!game->imgs[1][i])
		{
			free_images(game);
			return (0);
		}
	}
	return (1);
}

static int	get_frame_2(t_game *game)
{
	int		i;
	int		w;
	int		h;

	w = IMG_WIDTH;
	h = IMG_HEIGHT;
	game->imgs[2] = (void **)ft_calloc(sizeof(void *), MAX_IMG + 1);
	if (!game->imgs[2])
		return (0);
	game->imgs[2][0] = mlx_xpm_file_to_image(game->c_id, WALL_2, &w, &h);
	game->imgs[2][1] = mlx_xpm_file_to_image(game->c_id, BACK_2, &w, &h);
	game->imgs[2][2] = mlx_xpm_file_to_image(game->c_id, PLAYER_2, &w, &h);
	game->imgs[2][3] = mlx_xpm_file_to_image(game->c_id, COLLECT_2, &w, &h);
	game->imgs[2][4] = mlx_xpm_file_to_image(game->c_id, EXIT_2, &w, &h);
	i = -1;
	while (++i < MAX_IMG)
	{
		if (!game->imgs[2][i])
		{
			free_images(game);
			return (0);
		}
	}
	return (1);
}

int	get_images(t_game *game)
{
	game->imgs = (void ***)ft_calloc(sizeof(void **), FRAMES + 1);
	if (!game->imgs)
	{
		free_images(game);
		return (0);
	}
	if (!get_frame_0(game))
	{
		free_images(game);
		return (0);
	}
	if (!get_frame_1(game))
	{
		free_images(game);
		return (0);
	}
	if (!get_frame_2(game))
	{
		free_images(game);
		return (0);
	}
	return (1);
}
