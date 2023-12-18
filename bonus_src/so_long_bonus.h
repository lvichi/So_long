/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:34:15 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/17 23:53:43 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
#include <stdio.h> //delete

# define MAX_Y 20
# define MAX_X 38
# define MAX_FILE_SIZE 780
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define WALL_0 "images/0/wall.xpm"
# define BACK_0 "images/0/background.xpm"
# define PLAYER_0 "images/0/player.xpm"
# define COLLECT_0 "images/0/collect.xpm"
# define EXIT_0 "images/0/exit.xpm"
# define WALL_1 "images/1/wall.xpm"
# define BACK_1 "images/1/background.xpm"
# define PLAYER_1 "images/1/player.xpm"
# define COLLECT_1 "images/1/collect.xpm"
# define EXIT_1 "images/1/exit.xpm"
# define WALL_2 "images/2/wall.xpm"
# define BACK_2 "images/2/background.xpm"
# define PLAYER_2 "images/2/player.xpm"
# define COLLECT_2 "images/2/collect.xpm"
# define EXIT_2 "images/2/exit.xpm"
# define MAX_IMG 5
# define FRAMES 3
# define IMG_WIDTH 50
# define IMG_HEIGHT 50
# define WINDOW_NAME "./so_long"
# define FILE_EXTENSION ".ber"

typedef struct s_game
{
	void	*c_id;
	void	*w_id;
	void	***imgs;
	char	**map;
	int		p_yx[2];
	int		moves;
	int		collect;
	int		frame;
}	t_game;

char	**fill_map(char *buffer, char **map);
int		map_check(char **map);
void	*ft_calloc(size_t nmemb, size_t size);
int		check_extension(char *file, char *ext);
void	ft_putnbr(int n);
int		check_path(char **map);
int		array_len(char **array);
int		str_len(char *str);
void	free_images(t_game *game);
void	free_map(char **map);
void	print_map(char **map);
void	player_pos(t_game *game);
void	draw_map(t_game *game);
int		key_event(int key, t_game *game);
int		frame_loop(t_game *game);
int		end_game(t_game *game);
int		get_images(t_game *game);

#endif