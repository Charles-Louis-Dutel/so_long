/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_new_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:46:36 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/18 15:15:53 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	put_player(t_game *game, int xx, int yy)
{
	if (game->to_print == 'W')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_top, xx, yy);
	else if (game->to_print == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_bot, xx, yy);
	else if (game->to_print == 'A')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_left, xx, yy);
	else if (game->to_print == 'D')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.player_right, xx, yy);
}

static void	put_sprite_2(t_game *game, int x, int xx, int y, int yy)
{
	char	c;

	c = game->map[y][x];
	if (c == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.tree, xx, yy);
	else if (c == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.path, xx, yy);
	else if (c == 'P')
		put_player(game, xx, yy);
	else if (c == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.pokeball, xx, yy);
	else if (c == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.exit, xx, yy);
	else if (c == 'S')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->img.smogo_left, xx, yy);
}

int	print_map_move(t_game *game)
{
	if (game->n_enemy > 0)
		ennemy_move(game);
	if (game->update == 1)
	{
		int	x;
		int	xx;
		int	y;
		int	(yy) = 0;
		if (game->y <= 7)
			y = 0;
		else if (game->y > 7 && game->y < game->height - 7)
			y = game->y - 7;
		else
			y = game->height - 14;
		while (game->map[y])
		{
			if (game->x <= 15)
				x = 0;
			else if (game->x > 15 && game->x< game->len - 15)
				x = game->x - 15;
			else
				x = game->len - 30;
			xx = 0;
			while (game->map[y][x])
			{
				put_sprite_2(game, x, xx * 64, y, yy * 64 + 128);
				x++;
				xx++;
			}
			y++;
			yy++;
		}
		game->update = 0;
	}
	return (0);
}
