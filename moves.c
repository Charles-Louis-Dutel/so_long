/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 17:04:38 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/14 18:42:33 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_right(t_game *game)
{
	int	(x) = game->x;
	int (y) = game->y;

	if (game->map[y][x + 1] != '1')
	{
		if (game->map[y][x + 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x + 1] != 'E')
		{
			if (game->map[y][x + 1] == 'C')
				game->collectible--;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player, ((x + 1) * 64), (y * 64));
			game->map[y][x] = '0';
			game->map[y][x + 1] = 'P';
			game->x++;
		}
	}
}
void	move_left(t_game *game)
{
	int	(x) = game->x;
	int (y) = game->y;

	if (game->map[y][x - 1] != '1')
	{
		if (game->map[y][x - 1] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y][x - 1] != 'E')
		{
			if (game->map[y][x - 1] == 'C')
				game->collectible--;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player, ((x - 1) * 64), (y * 64));
			game->map[y][x] = '0';
			game->map[y][x - 1] = 'P';
			game->x--;
		}
	}
}
void	move_top(t_game *game)
{
	int	(x) = game->x;
	int (y) = game->y;

	if (game->map[y - 1][x] != '1')
	{
		if (game->map[y - 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y - 1][x] != 'E')
		{
			if (game->map[y - 1][x] == 'C')
				game->collectible--;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player, (x * 64), ((y - 1) * 64));
			game->map[y][x] = '0';
			game->map[y - 1][x] = 'P';
			game->y--;
		}
	}
}
void	move_bottom(t_game *game)
{
	int	(x) = game->x;
	int (y) = game->y;

	if (game->map[y + 1][x] != '1')
	{
		if (game->map[y + 1][x] == 'E' && game->collectible == 0)
			end_game(game);
		else if (game->map[y + 1][x] != 'E')
		{
			if (game->map[y + 1][x] == 'C')
				game->collectible--;
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.path, (x * 64), (y * 64));
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->img.player, (x * 64), ((y + 1) * 64));
			game->map[y][x] = '0';
			game->map[y + 1][x] = 'P';
			game->y++;
		}
	}
}
