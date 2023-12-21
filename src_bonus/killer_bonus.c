/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:05:58 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/21 18:16:49 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	killer_move_y(t_game *game)
{
	if (game->k_yx[0] - game->p_yx[0] > 0)
	{
		if (game->map[game->k_yx[0] - 1][game->k_yx[1]] == '0')
		{
			game->map[game->k_yx[0]][game->k_yx[1]] = '0';
			game->map[game->k_yx[0] - 1][game->k_yx[1]] = 'K';
			game->k_yx[0] = game->k_yx[0] - 1;
			return (1);
		}
		if (game->map[game->k_yx[0] - 1][game->k_yx[1]] == 'P')
			end_game(game);
	}
	else
	{
		if (game->map[game->k_yx[0] + 1][game->k_yx[1]] == '0')
		{
			game->map[game->k_yx[0]][game->k_yx[1]] = '0';
			game->map[game->k_yx[0] + 1][game->k_yx[1]] = 'K';
			game->k_yx[0] = game->k_yx[0] + 1;
			return (1);
		}
		if (game->map[game->k_yx[0] + 1][game->k_yx[1]] == 'P')
			end_game(game);
	}
	return (0);
}

static int	killer_move_x(t_game *game)
{
	if (game->k_yx[1] - game->p_yx[1] > 0)
	{
		if (game->map[game->k_yx[0]][game->k_yx[1] - 1] == '0')
		{
			game->map[game->k_yx[0]][game->k_yx[1]] = '0';
			game->map[game->k_yx[0]][game->k_yx[1] - 1] = 'K';
			game->k_yx[1] = game->k_yx[1] - 1;
			return (1);
		}
		if (game->map[game->k_yx[0]][game->k_yx[1] - 1] == 'P')
			end_game(game);
	}
	else
	{
		if (game->map[game->k_yx[0]][game->k_yx[1] + 1] == '0')
		{
			game->map[game->k_yx[0]][game->k_yx[1]] = '0';
			game->map[game->k_yx[0]][game->k_yx[1] + 1] = 'K';
			game->k_yx[1] = game->k_yx[1] + 1;
			return (1);
		}
		if (game->map[game->k_yx[0]][game->k_yx[1] + 1] == 'P')
			end_game(game);
	}
	return (0);
}

static void	killer_move(t_game *game)
{
	int	move;

	move = 0;
	if (abs(game->k_yx[0] - game->p_yx[0]) > abs(game->k_yx[1] - game->p_yx[1]))
	{
		move = killer_move_y(game);
		if (!move)
			killer_move_x(game);
	}
	else
	{
		move = killer_move_x(game);
		if (!move)
			killer_move_y(game);
	}
	if (move)
		draw_map(game);
}

int	killer_loop(t_game *game)
{
	static int	time;

	if (!(time % 100000))
	{
		killer_move(game);
	}
	time++;
	return (0);
}

void	killer_pos(t_game *game)
{
	int	i;
	int	j;	

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'K')
			{
				game->k_yx[0] = i;
				game->k_yx[1] = j;
				return ;
			}
		}
	}
	game->k_yx[0] = 0;
	game->k_yx[1] = 0;
}
