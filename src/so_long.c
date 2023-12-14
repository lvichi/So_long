/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:33:46 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/14 18:01:32 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_images(t_game *game)
{
	int		i;
	int		w;
	int		h;

	w = IMG_WIDTH;
	h = IMG_HEIGHT;
	game->imgs = (void **)ft_calloc(sizeof(void *), MAX_IMG + 1);
	if (!game->imgs)
		return (0);
	game->imgs[0] = mlx_xpm_file_to_image(game->c_id, WALL_IMG, &w, &h);
	game->imgs[1] = mlx_xpm_file_to_image(game->c_id, BACKGROUND_IMG, &w, &h);
	game->imgs[2] = mlx_xpm_file_to_image(game->c_id, PLAYER_IMG, &w, &h);
	game->imgs[3] = mlx_xpm_file_to_image(game->c_id, COLLECT_IMG, &w, &h);
	game->imgs[4] = mlx_xpm_file_to_image(game->c_id, EXIT_IMG, &w, &h);
	i = -1;
	while (++i < MAX_IMG)
	{
		if (!game->imgs[i])
		{
			free_images(game);
			return (0);
		}
	}
	return (1);
}

static int	mlx(t_game *game)
{
	game->c_id = mlx_init();
	if (!game->c_id)
	{
		free_map(game->map);
		return (-1);
	}
	if (!get_images(game))
	{
		mlx_destroy_display(game->c_id);
		free(game->c_id);
		free_map(game->map);
		return (-1);
	}
	game->w_id = mlx_new_window(game->c_id, array_len(game->map[0]) * 50,
			array_len(game->map) * 50, "./so_long");
	if (!game->w_id)
	{
		mlx_destroy_display(game->c_id);
		free(game->c_id);
		free_map(game->map);
		return (-1);
	}
	return (0);
}

static int	init_game(char *map)
{
	t_game	game;
	int		error;

	error = get_map(&game, map);
	if (error)
		return (error);
	if (mlx(&game))
		return (6);
	game.moves = 0;
	game.collect = 0;
	player_pos(&game);
	draw_map(&game);
	mlx_hook(game.w_id, 17, 0, end_game, &game);
	mlx_key_hook(game.w_id, key_event, &game);
	mlx_loop(game.c_id);
	return (0);
}

int	main(int argc, char **argv)
{
	int	error;

	if (argc != 2)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	error = init_game(argv[1]);
	if (error == 1)
		write(1, "Error reading file\n", 19);
	if (error == 2)
		write(1, "Invalid map: Not a retangle\n", 28);
	if (error == 3)
		write(1, "Invalid map: Invalid content\n", 29);
	if (error == 4)
		write(1, "Invalid map: Missing outside wall\n", 34);
	if (error == 5)
		write(1, "Invalid map: Invalid path\n", 26);
	if (error == 6)
		write(1, "Error loading game\n", 19);
}
