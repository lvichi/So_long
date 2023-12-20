/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:33:46 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/20 20:48:55 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	mlx(t_game *game)
{
	game->c_id = mlx_init();
	if (!game->c_id)
	{
		free_map(game->map);
		return (0);
	}
	if (!get_images(game))
	{
		mlx_destroy_display(game->c_id);
		free(game->c_id);
		free_map(game->map);
		return (0);
	}
	game->w_id = mlx_new_window(game->c_id, str_len(game->map[0]) * IMG_WIDTH,
			array_len(game->map) * IMG_HEIGHT, WINDOW_NAME);
	if (!game->w_id)
	{
		mlx_destroy_display(game->c_id);
		free(game->c_id);
		free_map(game->map);
		return (0);
	}
	return (1);
}

static int	get_map(t_game *game, char *file)
{
	ssize_t	fd;
	char	*buffer;
	char	**map;
	int		error;
	ssize_t	read_return;

	if (!check_extension(file, FILE_EXTENSION))
		return (8);
	fd = open(file, O_RDONLY);
	buffer = (char *)ft_calloc(sizeof(char), MAX_FILE_SIZE);
	map = (char **)ft_calloc(sizeof(char *), MAX_Y + 1);
	if (fd == -1 || !buffer || !map)
	{
		free(buffer);
		free(map);
		return (1);
	}
	read_return = read(fd, buffer, MAX_FILE_SIZE);
	if (read_return == -1)
		return (1);
	if (read_return == MAX_FILE_SIZE)
		return (7);
	game->map = fill_map(buffer, map);
	error = map_check(game->map);
	return (error);
}

static int	init_game(char *map)
{
	t_game	game;
	int		error;

	error = get_map(&game, map);
	if (error)
		return (error);
	if (!mlx(&game))
		return (6);
	game.moves = 0;
	game.collect = 0;
	game.frame = 0;
	player_pos(&game);
	draw_map(&game);
	mlx_hook(game.w_id, 17, (1L << 17), end_game, &game);
	mlx_hook(game.w_id, 02, (1L << 0), key_event, &game);
	mlx_loop_hook(game.c_id, frame_loop, &game);
	mlx_do_key_autorepeaton(game.c_id);
	//mlx_set_font(game.c_id, game.w_id, "-*-*-*-*-*-*-20-*-*-*-*-*-*-*-");
	mlx_loop(game.c_id);
	return (0);
}

int	main(int argc, char **argv)
{
	int	error;

	error = 0;
	if (argc != 2)
	{
		write(1, "Invalid arguments\n", 18);
		return (0);
	}
	error = init_game(argv[1]);
	if (error == 1)
		write(1, "Error reading file\n", 19);
	else if (error == 2)
		write(1, "Invalid map: Not a retangle\n", 28);
	else if (error == 3)
		write(1, "Invalid map: Invalid content\n", 29);
	else if (error == 4)
		write(1, "Invalid map: Missing outside wall\n", 34);
	else if (error == 5)
		write(1, "Invalid map: Invalid path\n", 26);
	else if (error == 6)
		write(1, "Error loading game\n", 19);
	else if (error == 7)
		write(1, "Invalid map: Map too big\n", 25);
	else if (error == 8)
		write(1, "Incorrect file\n", 15);
}
