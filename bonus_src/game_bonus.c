/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:13:25 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/20 17:09:22 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_move(t_game *game, int new_y, int new_x)
{
	if (game->map[new_y][new_x] == '0' || game->map[new_y][new_x] == 'C')
	{
		if (game->map[new_y][new_x] == 'C')
			game->collect -= 1;
		game->map[new_y][new_x] = 'P';
		game->map[(game->p_yx[0])][game->p_yx[1]] = '0';
		game->p_yx[0] = new_y;
		game->p_yx[1] = new_x;
		game->moves += 1;
		draw_map(game);
	}
	else if (game->map[new_y][new_x] == 'E' && game->collect == 0)
	{
		write(1, "\n", 1);
		end_game(game);
	}
}

int	key_event(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_UP)
		player_move(game, game->p_yx[0] - 1, game->p_yx[1]);
	else if (key == KEY_S || key == KEY_DOWN)
		player_move(game, game->p_yx[0] + 1, game->p_yx[1]);
	else if (key == KEY_A || key == KEY_LEFT)
		player_move(game, game->p_yx[0], game->p_yx[1] - 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		player_move(game, game->p_yx[0], game->p_yx[1] + 1);
	else if (key == KEY_ESC)
		end_game(game);
	return (0);
}

void	player_pos(t_game *game)
{
	int	i;
	int	j;	

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_yx[0] = i;
				game->p_yx[1] = j;
			}
			else if (game->map[i][j] == 'C')
				game->collect += 1;
		}
	}
}

void	free_images(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < FRAMES)
	{
		if (game->imgs[i])
		{
			j = -1;
			while (++j < MAX_IMG)
				if (game->imgs[i][j])
					mlx_destroy_image(game->c_id, game->imgs[i][j]);
			free(game->imgs[i]);
		}
	}
	free(game->imgs);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->c_id, game->w_id);
	free_images(game);
	free_map(game->map);
	mlx_destroy_display(game->c_id);
	free(game->c_id);
	exit(0);
	return (0);
}
