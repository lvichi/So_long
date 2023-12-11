/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:34:15 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/11 16:58:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_game
{
	void	*conn_id;
	void	*window_id;
	void	*images;
	char	**map;
	int		p_yx[2];
	int		moves;
	int		collect;
}	t_game;

char	**get_map(char *file);
void	map_size(char **map, int *map_x, int *map_y);
void	print_map(char **map);
void	*get_images(void *conn_id);
void	player_pos(t_game *game);
void	draw_map(t_game *game);
int		key_event(int key, t_game *game);
int		end_game(t_game *game);

#endif