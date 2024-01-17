/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel <cdutel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:00:52 by cdutel            #+#    #+#             */
/*   Updated: 2024/01/14 21:01:17 by cdutel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_img_player(t_game *game)
{
	int	pixels;

	pixels = 64;
	game->img.player_right = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_right.xpm", &pixels, &pixels);
	game->img.player_left = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_left.xpm", &pixels, &pixels);
	game->img.player_top = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_top.xpm", &pixels, &pixels);
	game->img.player_bot = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sacha_bot.xpm", &pixels, &pixels);
}

void	set_images(t_game *game)
{
	int	pixels;

	pixels = 64;
	game->img.tree = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/arbre.xpm", &pixels, &pixels);
	game->img.path = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/chemin.xpm", &pixels, &pixels);
	game->img.pokeball = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/pokeball.xpm", &pixels, &pixels);
	game->img.exit = mlx_xpm_file_to_image(game->mlx_ptr,
			"sprites/sortie.xpm", &pixels, &pixels);
	set_img_player(game);
}

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
