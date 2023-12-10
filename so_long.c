/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:33:46 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/10 23:19:36 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game(char **map)
{
	t_game	game;

	game.conn_id = mlx_init();
	game.window_id = mlx_new_window(game.conn_id, 1850, 1000, "./so_long");
	if (!game.conn_id || !game.window_id)
		return ;
	game.images = get_images(game.conn_id);
	if (!game.images)
		return ;
	game.map = map;
	game.moves = 0;
	game.collect = 0;
	player_pos(&game);
	draw_map(&game);
	mlx_hook(game.window_id, 17, 0, end_game, &game);
	mlx_key_hook(game.window_id, key_event, &game);
	mlx_loop(game.conn_id);
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
	game(map);
}
