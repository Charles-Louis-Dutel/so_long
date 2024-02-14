/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@42student.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/02/14 15:38:15 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_sprite(t_game *game, int x, int y)
{
	char	c;

	c = game->map[y / 64][x / 64];
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tree, x, y);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.path, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.pokeball, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, x, y);
}

void	print_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_sprite(game, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
