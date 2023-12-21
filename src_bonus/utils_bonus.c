/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/21 18:51:11 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_putnbr(int n)
{
	long	nbr;
	char	c;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		nbr = nbr % 10;
	}
	c = nbr + '0';
	write(1, &c, 1);
}

int	array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_extension(char *file, char *ext)
{
	char	ext_check[5];
	int		i;

	while (*file)
		file++;
	i = 5;
	while (--i >= 0)
		ext_check[i] = *file--;
	while (ext_check[++i])
		if (ext_check[i] != ext[i])
			return (0);
	return (1);
}

void	draw_str(t_game *game)
{
	char	*move;
	int		y;
	int		x;

	y = -1;
	while (++y < 30)
	{
		x = -1;
		while (++x < str_len(game->map[0]) * IMG_WIDTH)
			mlx_pixel_put(game->c_id, game->w_id, x, y, 0xFFFFFF);
	}
	mlx_string_put(game->c_id, game->w_id, 15, 21, 0x006600, "MOVEMENT: ");
	move = ft_itoa(game->moves);
	mlx_string_put(game->c_id, game->w_id, 100, 21, 0x006600, move);
	free(move);
}
