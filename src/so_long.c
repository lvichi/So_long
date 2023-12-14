/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:33:46 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/14 00:28:50 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_mlx(t_game *game, char **map, int map_x, int map_y)
{
	game->c_id = mlx_init();
	if (!game->c_id)
	{
		free_map(map);
		return (-1);
	}
	game->img = get_images(game->c_id);
	if (!game->img)
	{
		free(game->c_id);
		free_map(map);
		return (-1);
	}
	ft_putnbr_fd(map_x, 1);
	write(1, "\n", 1);
	ft_putnbr_fd(map_y, 1);
	write(1, "\n", 1);
	game->w_id = mlx_new_window(game->c_id, map_x, map_y, "./so_long");
	if (!game->w_id)
	{
		mlx_destroy_display(game->c_id);
		free(game->c_id);
		free_map(map);
		return (-1);
	}
	sleep(1);
	return (0);
}

static void	init_game(char **map)
{
	t_game	game;

	if (init_mlx(&game, map, (array_len(map[0]) - 1) * 50, array_len(map) * 50))
		return ;
	game.map = map;
	game.moves = 0;
	game.collect = 0;
	player_pos(&game);
	draw_map(&game);
	mlx_hook(game.w_id, 17, 0, end_game, &game);
	mlx_key_hook(game.w_id, key_event, &game);
	mlx_loop(game.c_id);
}

int	main(int argc, char **argv)
{
	char	**map;

	if (argc != 2)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	map = get_map(argv[1]);
	if (!map)
	{
		write(1, "Invalid map\n", 12);
		return (0);
	}
	print_map(map);
	init_game(map);
	write(1, "Error loading game\n", 19);
}
