/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 22:05:20 by lvichi            #+#    #+#             */
/*   Updated: 2023/12/15 01:36:28 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	free_images(t_game *game)
{
	int	i;

	i = -1;
	while (++i < MAX_IMG)
		if (game->imgs[i])
			mlx_destroy_image(game->c_id, game->imgs[i]);
	free(game->imgs);
}

int	array_len(void *array)
{
	int	array_check;
	int	i;

	i = 0;
	array_check = *((char *)array) >> 8;
	if (array_check)
	{
		while (*((char **)array))
		{
			array = (char **)array + 1;
			i++;
		}
	}
	else
	{
		while (*((char *)array))
		{
			array = (char *)array + 1;
			i++;
		}
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	size = nmemb * size;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	while (size)
		((char *)ret)[--size] = 0;
	return (ret);
}
